%language "c++"

%require "3.2"
%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%param { yy::Driver* driver }

%code requires
{
    
    #include <iostream>
    #include <string>
    #include <unordered_map>

    #include "include/Node.hpp"
    #include "include/ScopeNode.hpp"

    #include <memory>
    
    namespace yy { class Driver; }
 
}

%code
{
    #include "include/driver.hpp"
    extern std::shared_ptr<ScopeNode> currentScope;
    extern char* yytext;

    namespace yy { parser::token_type yylex(parser::semantic_type* yyval, Driver* driver); }
}

%token
    ASSIGN          "="
    MINUS           "-"
    PLUS            "+"
    SCOLON          ";"
    MULTIPLY        "*" 
    DIVIDE          "/"
    LPAREN          "("
    RPAREN          ")"
    LBRACE          "{"
    RBRACE          "}"
    LESS            "<"
    GREATER         ">"
    GREATEREQ       ">="
    LESSEQ          "<="
    NONEQUAL        "!="
    EQUAL           "=="
    AND             "&&"
    OR              "||"
    QUESTION_MARK   "?"

    IF              "if"
    WHILE           "while"
    ELSE            "else"
    PRINT           "print"
    ERR
;

%token <int> NUM
%token <std::string> ID_string

%nterm <std::shared_ptr<ASTNode>> GetId
%nterm <std::shared_ptr<ASTNode>> SetId
%nterm <std::shared_ptr<ASTNode>> stmt_list
%nterm <std::shared_ptr<ASTNode>> stmt
%nterm <std::shared_ptr<ASTNode>> assign_stmt
%nterm <std::shared_ptr<ASTNode>> expr
%nterm <std::shared_ptr<ASTNode>> stmt_1
%nterm <std::shared_ptr<ASTNode>> stmt_2
%nterm <std::shared_ptr<ASTNode>> bool_expr
%nterm <std::shared_ptr<ASTNode>> arith_expr
%nterm <std::shared_ptr<ASTNode>> term
%nterm <std::shared_ptr<ASTNode>> primary_expr
%nterm <std::shared_ptr<ASTNode>> open_sc
%nterm <std::shared_ptr<ASTNode>> close_sc
%nterm <std::shared_ptr<ASTNode>> scope


%left AND OR
%right ASSIGN
%left EQUAL NONEQUAL
%left LESS LESSEQ GREATER GREATEREQ 
%left PLUS MINUS
%left MULTIPLY DIVIDE

%start program

%%

program: stmt_list  
{ 
    driver->globalAstNode->calculate(); 
    driver->globalAstNode->dump_ast(driver->dump_file);
} 
;

stmt_list: stmt | stmt_list stmt                           
;


scope: open_sc stmt_list close_sc      
{
    $$ = $1;
}
;

open_sc: "{"    
{
    auto new_scope = std::make_shared<ScopeNode>(driver->currentScope); 
    driver->currentScope->pushToSuccessors(new_scope);
    driver->currentScope = new_scope;

    driver->globalAstNode = std::shared_ptr<ASTNode>(new GlobalAst(driver->currentScope, driver->globalAstNode));
    $$ = driver->globalAstNode;
}
;

close_sc: "}"   
{
    driver->currentScope = driver->currentScope->exit_scope(); 
    driver->globalAstNode = std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->predessor.lock();
}
;

stmt: stmt_1 | stmt_2               
;

stmt_1:   assign_stmt   

| PRINT primary_expr                       
{    
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new OutputNode($2, driver->currentScope)));
}

| scope

| expr ";" 

| IF "(" expr ")" stmt_1 ELSE stmt_1    
{ 

    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new IfNode($3, $5, $7, driver->currentScope)));
}

| WHILE "(" expr ")" stmt_1 
{ 
    $$ = std::shared_ptr<ASTNode>(new WhileNode($3, $5, driver->currentScope)); 
}
;

stmt_2: IF "(" expr ")" stmt         
{ 
    $$ = std::shared_ptr<ASTNode> (new IfNode($3, $5, 0, driver->currentScope)); 
}

| IF "(" expr ")" stmt_1 ELSE stmt_2        
{ 
    $$ = std::shared_ptr<ASTNode>(new IfNode($3, $5, $7, driver->currentScope)); 
}

| WHILE "(" expr ")" stmt_2                 
{ 
    $$ = std::shared_ptr<ASTNode>(new WhileNode($3, $5, driver->currentScope)); 
}
;

assign_stmt: SetId "=" expr ";"          
{    
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new AssignmentNode($1, $3, driver->currentScope)));                                    
}
| SetId "=" QUESTION_MARK ";"
{
    auto Input = std::shared_ptr<ASTNode>(new InputNode(driver->currentScope));
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new AssignmentNode($1, Input, driver->currentScope)));
}
;

SetId: ID_string                            
{
    $$ = createSetIdNode($1, driver->currentScope); 
}
;                 

expr: expr AND bool_expr                    
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::And, $3, driver->currentScope)); 
}

| expr OR bool_expr                         
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Or, $3, driver->currentScope)); 
}

| bool_expr                                 
;

bool_expr: bool_expr GREATEREQ arith_expr   
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::GreaterEq, $3, driver->currentScope)); 
}

| bool_expr LESSEQ arith_expr               
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::LessEq, $3, driver->currentScope)); 
}

| bool_expr LESS arith_expr                 
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Less, $3, driver->currentScope)); 
}

| bool_expr GREATER arith_expr              
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Greater, $3, driver->currentScope)); 
}

| bool_expr EQUAL arith_expr                
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Equal, $3, driver->currentScope)); 
}

| bool_expr NONEQUAL arith_expr             
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::NonEqual, $3, driver->currentScope)); 
}

| arith_expr                               
;

arith_expr: arith_expr PLUS term            
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Plus, $3, driver->currentScope));
}

| arith_expr MINUS term                     
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Minus, $3, driver->currentScope)); 
}

| term                                      

;

term: term MULTIPLY primary_expr            
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Multiply, $3, driver->currentScope)); 
}

| term DIVIDE primary_expr                  
{ 
    $$ = std::shared_ptr<ASTNode>(new BinaryNode($1, BinaryOp::Divide, $3, driver->currentScope)); 
}
    
| primary_expr                              
;

primary_expr: MINUS primary_expr            
{ 
    $$ = std::shared_ptr<ASTNode>(new UnaryNode(UnaryOp::Minus, $2, driver->currentScope)); 
}
       
| "(" expr ")"                              
{ 
    $$ = $2; 
}

       
| NUM                                       
{ 
    $$ = std::shared_ptr<ASTNode>(new NumNode($1, driver->currentScope)); 
}

| GetId 
     
;

GetId: ID_string                            
{
    $$ = createGetIdNode($1, driver->currentScope); 
}
;


%%
 


namespace yy {
    parser::token_type yylex(parser::semantic_type* yyval,
                             Driver* driver)
    {
        return driver->yylex(yyval);
    }
    void parser::error(const std::string&) {}
}