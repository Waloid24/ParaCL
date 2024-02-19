%language "c++"
%skeleton "lalr1.cc"

%defines
%define api.value.type variant
%define parse.error custom
%param {yy::Driver* driver}

%locations

%code requires
{
    #include "../include/node.hpp"

    // forward decl of argument to parser
    namespace yy { class Driver; }
}

%code
{
    #include "../include/driver.hpp"

    using namespace nodes;

    namespace yy {

        parser::token_type yylex(parser::semantic_type* yylval, 
                                 parser::location_type* yyloc, Driver* driver);
    
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
    NOT             "!"
    
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
                                            driver->process();
                                        }
;

stms:     statement                     {
                                            driver->add_branch($1);
                                        }
        | stms statement                {
                                            driver->add_branch($2);
                                        }
;

scope: open_scope stms close_scope      {
                                            $$ = $3;
                                        }
;

open_scope: "{"                         {
                                            driver->cur_scope_ = new Scope_node(driver->cur_scope_);
                                        }
;

close_scope: "}"                        {
                                            $$ = driver->cur_scope_;
                                            driver->cur_scope_ = driver->cur_scope_->reset_scope();
                                        }
;

statement:    open_statement            {
                                            $$ = $1;
                                        }
            | closed_statement          {
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
                                            $$ = $1;
                                        }
                    | scope             {
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

simple_statement:     assign SCOLON     {
                                            $$ = $1;
                                        }
                    | expression SCOLON {
                                            $$ = $1;
                                        }
                    | OUTPUT expression SCOLON  
                                        {
                                            $$ = new Func_node(func_type::OUTPUT, $2);
                                        }
;

assign:   
        lval ASSIGN INPUT               {
                                            Func_node* f_node = new Func_node(func_type::INPUT);
                                            $$ = new Bin_op_node(bin_op_type::ASSIGN, $1, f_node);
                                        }   
        | lval ASSIGN expression        {
                                            $$ = new Bin_op_node(bin_op_type::ASSIGN, $1, $3);
                                        }
;

lval: ID                                {
                                            Var* var = driver->lookup($1);
                                            if (var == nullptr)
                                            {
                                                var = new Var{};
                                                driver->emplace($1, var);
                                            }

                                            $$ = new Id_node($1, var);
                                        }
;

expression:   expression "&&" boolean   {   
                                            $$ = new Bin_op_node(bin_op_type::AND, $1, $3);
                                        }
            | expression "||" boolean   {
                                            $$ = new Bin_op_node(bin_op_type::OR, $1, $3);
                                        }
            | boolean                   {
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
                                            $$ = $1;
                                        }
;

primary:      "-" primary               {
                                            $$ = new Un_op_node(un_op_type::U_MINUS, $2);
                                        }
            | "!" primary               {
                                            $$= new Un_op_node(un_op_type::NOT, $2);
                                        }
            | "(" assign ")"            {
                                            $$ = $2;
                                        }
            | "(" expression ")"        {
                                            $$ = $2;
                                        }
            | INTEGER                   {
                                            $$ = new Integer_node($1); 
                                        }
            | ID                        {
                                            Var* var = driver->lookup($1);
                                            if (var == nullptr)
                                            {
                                                driver->report_name_error(@1, $1);
                                            }
                                            $$ = new Id_node($1, var);
                                        }
;

%%

namespace yy {

parser::token_type yylex(parser::semantic_type* yylval, 
                         parser::location_type* yyloc, Driver* driver)
{
  return driver->yylex(yylval, yyloc);
}

void parser::error(const parser::location_type& loc, const std::string& message) {
    std::cerr << message << " in line " << loc.begin.line << std::endl;
}

void yy::parser::report_syntax_error(yy::parser::context const& ctx) const {
    driver->report_syntax_error(ctx);
}

}