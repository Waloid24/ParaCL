%language "c++"
%skeleton "lalr1.cc"

%defines
%define api.value.type variant
%param {yy::Driver* driver}

%code requires
{
    #include "../include/node.hpp"
    #include "../include/symtab.hpp"

    //TODO: why #include driver from %code{} section doesn't work?

    // forward decl of argument to parser
    namespace yy { class Driver; }
}

%code
{
    #include "../include/driver.hpp"

    using namespace nodes;

    namespace yy {

        parser::token_type yylex(parser::semantic_type* yylval, Driver* driver);
    
    }

}

%token
    IF              "if"
    ELSE            "else"
    WHILE           "while"

    OUTPUT          "print"
    INPUT           "?"

    LRB             "("
    RRB             ")"
    LCB             "{"
    RCB             "}"
    SCOLON          ";"

    LESS            "<"
    LESS_EQUAL      "<="
    GREATER         ">"
    GREATER_EQUAL   ">="
    EQUAL           "=="
    NOT_EQUAL       "!="

    AND             "&&"
    OR              "||"
    
    ASSIGN          "="

    MINUS           "-"
    PLUS            "+"

    MUL             "*"
    DIV             "/"
    
    ERR
;

%token <int> INTEGER
%token <std::string> ID

%nterm <nodes::Base_node*> program
%nterm <nodes::Base_node*> stms
%nterm <nodes::Base_node*> scope
%nterm <nodes::Base_node*> open_scope
%nterm <nodes::Base_node*> close_scope
%nterm <nodes::Base_node*> statement
%nterm <nodes::Base_node*> closed_statement
%nterm <nodes::Base_node*> open_statement
%nterm <nodes::Base_node*> simple_statement
%nterm <nodes::Base_node*> assign
%nterm <nodes::Base_node*> lval
%nterm <nodes::Base_node*> expression
%nterm <nodes::Base_node*> boolean
%nterm <nodes::Base_node*> arithmetic
%nterm <nodes::Base_node*> term
%nterm <nodes::Base_node*> primary

/* Priority * and / is higher than + and - */
%left AND OR
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL 
%left PLUS MINUS
%left MUL DIV

/* the start symbol for the grammar is 'statement', isn't the
 * first nonterminal specified in the grammar specification section. */
%start program

%%

program: stms                           {
                                            std::cout << "Into program: stms" << std::endl;
                                            driver->process();
                                        }
;

stms:     statement                     {
                                            std::cout << "stms: statement" << std::endl;
                                            driver->add_branch($1);
                                        }
        | stms statement                {
                                            std::cout << "stms: stms statement" << std::endl;
                                            driver->add_branch($2);
                                        }
;

scope: open_scope stms close_scope      {
                                            std::cout << "scope:" << std::endl;
                                            $$ = $3;
                                        }
;

open_scope: "{"                         {
                                            std::cout << "open_scope:" << std::endl;
                                            driver->cur_scope_ = new Scope_node(driver->cur_scope_);
                                        }
;

close_scope: "}"                        {
                                            std::cout << "close_scope:" << std::endl;
                                            $$ = driver->cur_scope_;
                                            driver->cur_scope_ = driver->cur_scope_->reset_scope();
                                        }
;

statement:    open_statement            {
                                            std::cout << "statement: open_statement" << std::endl;
                                            $$ = $1;
                                        }
            | closed_statement          {
                                            std::cout << "statement: closed_statement" << std::endl;
                                            $$ = $1;
                                        }
;

open_statement:   IF "(" expression ")" statement
                                        {
                                            $$ = new If_node($3, $5);
                                        }
                | IF "(" expression ")" closed_statement ELSE open_statement
                                        {
                                            $$ = new If_node($3, $5, $7);
                                        }
                | WHILE "(" expression ")" open_statement
                                        {
                                            $$ = new While_node($3, $5);
                                        }
;

closed_statement:     simple_statement  {
                                            std::cout << "closed_statement: simple_statement" << std::endl;
                                            $$ = $1;
                                        }
                    | scope             {
                                            std::cout << "closed_statement: scope" << std::endl;
                                            $$ = $1;
                                        }
                    | IF "(" expression ")" closed_statement ELSE closed_statement
                                        {
                                            $$ = new If_node($3, $5, $7);
                                        }
                    | WHILE "(" expression ")" closed_statement
                                        {
                                            $$ = new While_node($3, $5);
                                        }
;

simple_statement:     assign            {
                                            std::cout << "simple_statement: assign" << std::endl;
                                            $$ = $1;
                                        }
                    | expression SCOLON {
                                            std::cout << "simple_statement: expression" << std::endl;
                                            $$ = $1;
                                        }
                    | OUTPUT expression SCOLON  
                                        {
                                            std::cout << "simple_statement: OUTPUT" << std::endl;
                                            $$ = new Func_node(func_type::OUTPUT, $2);
                                        }
;

assign:   
        lval ASSIGN INPUT SCOLON      {
                                            std::cout << "assign: lval INPUT" << std::endl;
                                            Func_node* f_node = new Func_node(func_type::INPUT);
                                            $$ = new Bin_op_node(bin_op_type::ASSIGN, $1, f_node);
                                        }   
        | lval ASSIGN expression SCOLON {
                                            std::cout << "assign: lval ..." << std::endl;
                                            $$ = new Bin_op_node(bin_op_type::ASSIGN, $1, $3);
                                        }
;

lval: ID                                {
                                            std::cout << "lval: ID ()" << std::endl;
                                            Var* var = driver->lookup($1);
                                            if (var == nullptr)
                                            {
                                                var = new Var{};
                                                driver->emplace($1, var);
                                            }

                                            $$ = new Id_node($1, var);
                                            std::cout << "lval: ID (end)" << std::endl;
                                        }
;

expression:   expression "&&" boolean   {   
                                            $$ = new Bin_op_node(bin_op_type::AND, $1, $3);
                                        }
            | expression "||" boolean   {
                                            $$ = new Bin_op_node(bin_op_type::OR, $1, $3);
                                        }
            | boolean                   {
                                            std::cout << "expression: boolean" << std::endl;
                                            $$ = $1;
                                        }
;

boolean:      boolean "==" arithmetic   {
                                            $$ = new Bin_op_node(bin_op_type::EQUAL, $1, $3);
                                        }
            | boolean "!=" arithmetic   {
                                            $$ = new Bin_op_node(bin_op_type::NOT_EQUAL, $1, $3);
                                        }
            | boolean ">" arithmetic    {
                                            $$ = new Bin_op_node(bin_op_type::GREATER, $1, $3);
                                        }
            | boolean ">=" arithmetic   {
                                            $$ = new Bin_op_node(bin_op_type::GREATER_EQUAL, $1, $3);
                                        }
            | boolean "<" arithmetic    {
                                            $$ = new Bin_op_node(bin_op_type::LESS, $1, $3);
                                        }
            | boolean "<=" arithmetic   {
                                            $$ = new Bin_op_node(bin_op_type::LESS_EQUAL, $1, $3);
                                        }
            | arithmetic                {
                                            std::cout << "boolean: arithmetic" << std::endl;
                                            $$ = $1;
                                        }
;

arithmetic:   arithmetic "+" term       {
                                            $$ = new Bin_op_node(bin_op_type::PLUS, $1, $3);
                                        }
            | arithmetic "-" term       {
                                            $$ = new Bin_op_node(bin_op_type::MINUS, $1, $3);
                                        }
            | term                      {
                                            std::cout << "arithmetic: term" << std::endl;
                                            $$ = $1;
                                        }
;

term:         term "*" primary          {
                                            $$ = new Bin_op_node(bin_op_type::MUL, $1, $3);
                                        }
            | term "/" primary          {
                                            $$ = new Bin_op_node(bin_op_type::DIV, $1, $3);
                                        }
            | primary                   {
                                            std::cout << "term: primary:" << std::endl;
                                            $$ = $1;
                                        }
;

primary:      "-" primary               {
                                            $$ = new Un_op_node(un_op_type::U_MINUS,
                                                                $2);
                                        }
            | "(" expression ")"        {
                                            std::cout << "primary: ( expression )" << std::endl;
                                            $$ = $2;
                                        }
            | INTEGER                   { 
                                            std::cout << "primary: INTEGER" << std::endl;
                                            $$ = new Integer_node($1); 
                                        }
            | ID                        { 
                                            std::cout << "primary: ID" << std::endl;

                                            Var* var = driver->lookup($1);
                                            if (var == nullptr)
                                            {
                                                /* YYLTYPE *info = &@1;
                                                printError("Using undeclared variable! %s - Line %d:c%d to %d:c%d",
                                                            $1,
                                                            info->first_line, info->first_column,
                                                            info->last_line, info->last_column); */
                                                std::cout << "You have an error, haha" << std::endl;
                                            }
                                            $$ = new Id_node($1, var);
                                        }
;

%%

namespace yy {

parser::token_type yylex(parser::semantic_type* yylval,                         
                         Driver* driver)
{
  return driver->yylex(yylval);
}

void parser::error(const std::string&){}
}