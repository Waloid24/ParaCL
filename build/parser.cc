// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "compiler.tab.hh"


// Unqualified %code blocks.
#line 26 "compiler.y"

    #include "include/driver.hpp"
    extern std::shared_ptr<ScopeNode> currentScope;
    extern char* yytext;

    namespace yy { parser::token_type yylex(parser::semantic_type* yyval, Driver* driver); }

#line 53 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 125 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"


  /// Build a parser object.
  parser::parser (yy::Driver* driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 27: // NUM
        value.move< int > (std::move (that.value));
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.move< std::shared_ptr<ASTNode> > (std::move (that.value));
        break;

      case 28: // ID_string
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 27: // NUM
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.copy< std::shared_ptr<ASTNode> > (YY_MOVE (that.value));
        break;

      case 28: // ID_string
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 27: // NUM
        value.move< int > (YY_MOVE (s.value));
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.move< std::shared_ptr<ASTNode> > (YY_MOVE (s.value));
        break;

      case 28: // ID_string
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 27: // NUM
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.YY_MOVE_OR_COPY< std::shared_ptr<ASTNode> > (YY_MOVE (that.value));
        break;

      case 28: // ID_string
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 27: // NUM
        value.move< int > (YY_MOVE (that.value));
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.move< std::shared_ptr<ASTNode> > (YY_MOVE (that.value));
        break;

      case 28: // ID_string
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 27: // NUM
        value.copy< int > (that.value);
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.copy< std::shared_ptr<ASTNode> > (that.value);
        break;

      case 28: // ID_string
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 27: // NUM
        value.move< int > (that.value);
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        value.move< std::shared_ptr<ASTNode> > (that.value);
        break;

      case 28: // ID_string
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 27: // NUM
        yylhs.value.emplace< int > ();
        break;

      case 30: // GetId
      case 31: // SetId
      case 32: // stmt_list
      case 33: // stmt
      case 34: // assign_stmt
      case 35: // expr
      case 36: // stmt_1
      case 37: // stmt_2
      case 38: // bool_expr
      case 39: // arith_expr
      case 40: // term
      case 41: // primary_expr
      case 42: // open_sc
      case 43: // close_sc
      case 44: // scope
        yylhs.value.emplace< std::shared_ptr<ASTNode> > ();
        break;

      case 28: // ID_string
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 94 "compiler.y"
{ 
    driver->globalAstNode->dump_ast(driver->dump_file);
    driver->globalAstNode->calculate(); 
}
#line 799 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 3:
#line 100 "compiler.y"
           { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 805 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 4:
#line 100 "compiler.y"
                  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[1].value.as < std::shared_ptr<ASTNode> > (); }
#line 811 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 5:
#line 105 "compiler.y"
{
    yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[2].value.as < std::shared_ptr<ASTNode> > ();
}
#line 819 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 6:
#line 111 "compiler.y"
{
    auto new_scope = std::make_shared<ScopeNode>(driver->currentScope); 
    driver->currentScope->pushToSuccessors(new_scope);
    driver->currentScope = new_scope;

    driver->globalAstNode = std::shared_ptr<ASTNode>(new GlobalAst(driver->currentScope, driver->globalAstNode));
    yylhs.value.as < std::shared_ptr<ASTNode> > () = driver->globalAstNode;
}
#line 832 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 7:
#line 122 "compiler.y"
{
    driver->currentScope = driver->currentScope->exit_scope(); 
    driver->globalAstNode = std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->predessor.lock();
}
#line 841 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 8:
#line 128 "compiler.y"
      { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 847 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 9:
#line 128 "compiler.y"
               { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 853 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 10:
#line 131 "compiler.y"
          { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 859 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 11:
#line 134 "compiler.y"
{    
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new OutputNode(yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)));
}
#line 867 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 12:
#line 138 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 873 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 13:
#line 140 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[1].value.as < std::shared_ptr<ASTNode> > (); }
#line 879 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 14:
#line 143 "compiler.y"
{ 

    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new IfNode(yystack_[4].value.as < std::shared_ptr<ASTNode> > (), yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)));
}
#line 888 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 15:
#line 149 "compiler.y"
{ 
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new WhileNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope))); 
}
#line 896 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 16:
#line 155 "compiler.y"
{ 
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode> (new IfNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), 0, driver->currentScope))); 
}
#line 904 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 17:
#line 160 "compiler.y"
{ 
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new IfNode(yystack_[4].value.as < std::shared_ptr<ASTNode> > (), yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope))); 
}
#line 912 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 18:
#line 165 "compiler.y"
{ 
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new WhileNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope))); 
}
#line 920 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 19:
#line 171 "compiler.y"
{    
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new AssignmentNode(yystack_[3].value.as < std::shared_ptr<ASTNode> > (), yystack_[1].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)));                                    
}
#line 928 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 20:
#line 175 "compiler.y"
{
    auto Input = std::shared_ptr<ASTNode>(new InputNode(driver->currentScope));
    std::dynamic_pointer_cast<GlobalAst>(driver->globalAstNode)->create_child(std::shared_ptr<ASTNode>(new AssignmentNode(yystack_[3].value.as < std::shared_ptr<ASTNode> > (), Input, driver->currentScope)));
}
#line 937 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 21:
#line 182 "compiler.y"
{
    yylhs.value.as < std::shared_ptr<ASTNode> > () = createSetIdNode(yystack_[0].value.as < std::string > (), driver->currentScope); 
}
#line 945 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 22:
#line 188 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::And, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 953 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 23:
#line 193 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Or, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 961 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 24:
#line 197 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 967 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 25:
#line 201 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::GreaterEq, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 975 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 26:
#line 206 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::LessEq, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 983 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 27:
#line 211 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Less, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 991 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 28:
#line 216 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Greater, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 999 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 29:
#line 221 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Equal, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 1007 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 30:
#line 226 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::NonEqual, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 1015 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 31:
#line 230 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 1021 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 32:
#line 234 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Plus, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope));
}
#line 1029 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 33:
#line 239 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Minus, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 1037 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 34:
#line 243 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 1043 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 35:
#line 248 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Multiply, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 1051 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 36:
#line 253 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Divide, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 1059 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 37:
#line 257 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 1065 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 38:
#line 261 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new UnaryNode(UnaryOp::Minus, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 1073 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 39:
#line 266 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[1].value.as < std::shared_ptr<ASTNode> > (); 
}
#line 1081 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 40:
#line 272 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new NumNode(yystack_[0].value.as < int > (), driver->currentScope)); 
}
#line 1089 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 41:
#line 276 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 1095 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 42:
#line 281 "compiler.y"
{
    yylhs.value.as < std::shared_ptr<ASTNode> > () = createGetIdNode(yystack_[0].value.as < std::string > (), driver->currentScope); 
}
#line 1103 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;


#line 1107 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -60;

  const signed char parser::yytable_ninf_ = -22;

  const signed char
  parser::yypact_[] =
  {
      13,    23,    23,   -60,    21,    72,    23,   -60,    42,   -60,
      49,    13,   -60,   -60,    -1,   -60,   -60,    52,     7,    51,
     -60,    13,   -60,    16,   -60,   -60,    -6,    23,    23,   -60,
      33,   -60,   -60,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    -2,   -60,   -60,    29,    43,
      76,    27,    52,    52,     7,     7,     7,     7,     7,     7,
      51,    51,   -60,   -60,   -60,   -60,    13,    13,   -60,   -60,
     -60,    59,   -60,   -60,    13,   -60,   -60
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     6,     0,     0,     0,    40,    42,    41,
       0,     2,     3,    10,     0,     8,     9,    24,    31,    34,
      37,     0,    12,     0,    42,    38,     0,     0,     0,    11,
       0,     4,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    39,     0,     0,
       0,     0,    22,    23,    27,    28,    25,    26,    30,    29,
      33,    32,    35,    36,     7,     5,     0,     0,    20,    19,
      16,     8,    15,    18,     0,    14,    17
  };

  const signed char
  parser::yypgoto_[] =
  {
     -60,   -60,   -60,    63,   -11,   -60,     1,   -10,   -59,    44,
      36,    38,     0,   -60,   -60,   -60,   -60
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    65,    22,    23
  };

  const signed char
  parser::yytable_[] =
  {
      31,    25,     1,    26,    47,    32,    29,     2,    73,     3,
      64,    41,    42,    33,    34,    76,    46,     1,    33,    34,
       4,     5,     2,     6,     3,     7,     8,     1,    48,    49,
      27,    51,     2,    69,    31,     4,     5,     1,     6,    66,
       7,     8,     2,    62,    63,   -21,    33,    34,    33,    34,
       7,    24,    30,    67,    50,    70,    71,    72,    43,    44,
       7,    24,    33,    34,    75,    35,    36,    37,    38,    39,
      40,    54,    55,    56,    57,    58,    59,    52,    53,    60,
      61,    28,    68,    74,    45
  };

  const signed char
  parser::yycheck_[] =
  {
      11,     1,     4,     2,    10,     6,     6,     9,    67,    11,
      12,     4,     5,    19,    20,    74,     0,     4,    19,    20,
      22,    23,     9,    25,    11,    27,    28,     4,    27,    28,
       9,    30,     9,     6,    45,    22,    23,     4,    25,    10,
      27,    28,     9,    43,    44,     3,    19,    20,    19,    20,
      27,    28,     3,    10,    21,    66,    66,    67,     7,     8,
      27,    28,    19,    20,    74,    13,    14,    15,    16,    17,
      18,    35,    36,    37,    38,    39,    40,    33,    34,    41,
      42,     9,     6,    24,    21
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,     9,    11,    22,    23,    25,    27,    28,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    44,    45,    28,    41,    35,     9,     9,    41,
       3,    33,     6,    19,    20,    13,    14,    15,    16,    17,
      18,     4,     5,     7,     8,    32,     0,    10,    35,    35,
      21,    35,    38,    38,    39,    39,    39,    39,    39,    39,
      40,    40,    41,    41,    12,    43,    10,    10,     6,     6,
      33,    36,    36,    37,    24,    36,    37
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    29,    45,    32,    32,    44,    42,    43,    33,    33,
      36,    36,    36,    36,    36,    36,    37,    37,    37,    34,
      34,    31,    35,    35,    35,    38,    38,    38,    38,    38,
      38,    38,    39,    39,    39,    40,    40,    40,    41,    41,
      41,    41,    30
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     2,     1,     2,     7,     5,     5,     7,     5,     4,
       4,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     2,     3,
       1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"=\"", "\"-\"", "\"+\"", "\";\"",
  "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\"<\"", "\">\"",
  "\">=\"", "\"<=\"", "\"!=\"", "\"==\"", "\"&&\"", "\"||\"", "\"?\"",
  "\"if\"", "\"while\"", "\"else\"", "\"print\"", "ERR", "NUM",
  "ID_string", "$accept", "GetId", "SetId", "stmt_list", "stmt",
  "assign_stmt", "expr", "stmt_1", "stmt_2", "bool_expr", "arith_expr",
  "term", "primary_expr", "open_sc", "close_sc", "scope", "program", YY_NULLPTR
  };


  const short
  parser::yyrline_[] =
  {
       0,    93,    93,   100,   100,   104,   110,   121,   128,   128,
     131,   133,   138,   140,   142,   148,   154,   159,   164,   170,
     174,   181,   187,   192,   197,   200,   205,   210,   215,   220,
     225,   230,   233,   238,   243,   247,   252,   257,   260,   265,
     271,   276,   280
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
    };
    const int user_token_number_max_ = 283;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 1495 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"

#line 287 "compiler.y"


namespace yy {
    parser::token_type yylex(parser::semantic_type* yyval,
                             Driver* driver)
    {
        return driver->yylex(yyval);
    }
    void parser::error(const std::string&) {}
}
