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

#line 53 "compiler.tab.cc"


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
#line 125 "compiler.tab.cc"


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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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

      case 35: // stmt_list
      case 36: // stmt
      case 37: // assign_stmt
      case 38: // expr
      case 39: // stmt_1
      case 40: // stmt_2
      case 41: // bool_expr
      case 42: // arith_expr
      case 43: // term
      case 44: // primary_expr
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
    driver->globalAstNode->calculate(); 
    driver->globalAstNode->dump_ast();
    std::cout << "program" << std::endl;
}
#line 760 "compiler.tab.cc"
    break;

  case 3:
#line 105 "compiler.y"
                                {std::cout << "stmt" << std::endl;  }
#line 766 "compiler.tab.cc"
    break;

  case 4:
#line 106 "compiler.y"
                                  {std::cout << "stmt stmt list" << std::endl;  }
#line 772 "compiler.tab.cc"
    break;

  case 6:
#line 111 "compiler.y"
                                             {std::cout << "expr" << std::endl;  }
#line 778 "compiler.tab.cc"
    break;

  case 7:
#line 114 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new IfNode(yystack_[4].value.as < std::shared_ptr<ASTNode> > (), yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 786 "compiler.tab.cc"
    break;

  case 8:
#line 119 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new WhileNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 794 "compiler.tab.cc"
    break;

  case 9:
#line 123 "compiler.y"
                {std::cout << "assig stmt" << std::endl;}
#line 800 "compiler.tab.cc"
    break;

  case 10:
#line 139 "compiler.y"
{ yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode> (new IfNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), 0, driver->currentScope)); }
#line 806 "compiler.tab.cc"
    break;

  case 11:
#line 142 "compiler.y"
{ yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new IfNode(yystack_[4].value.as < std::shared_ptr<ASTNode> > (), yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); }
#line 812 "compiler.tab.cc"
    break;

  case 12:
#line 145 "compiler.y"
{ yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new WhileNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); }
#line 818 "compiler.tab.cc"
    break;

  case 13:
#line 148 "compiler.y"
      { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 824 "compiler.tab.cc"
    break;

  case 14:
#line 148 "compiler.y"
               { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 830 "compiler.tab.cc"
    break;

  case 15:
#line 152 "compiler.y"
{ 
    //$$ = std::shared_ptr<ASTNode>(new AssignmentNode($1, $3, driver->currentScope)); 
    std::cout << "Assign";       
    driver->globalAstNode->create_child(std::shared_ptr<ASTNode>(new AssignmentNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)));                                    
}
#line 840 "compiler.tab.cc"
    break;

  case 16:
#line 174 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::And, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 848 "compiler.tab.cc"
    break;

  case 17:
#line 179 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Or, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 856 "compiler.tab.cc"
    break;

  case 18:
#line 183 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 862 "compiler.tab.cc"
    break;

  case 19:
#line 187 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::GreaterEq, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 870 "compiler.tab.cc"
    break;

  case 20:
#line 192 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::LessEq, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 878 "compiler.tab.cc"
    break;

  case 21:
#line 197 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Less, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 886 "compiler.tab.cc"
    break;

  case 22:
#line 202 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Greater, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 894 "compiler.tab.cc"
    break;

  case 23:
#line 207 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Equal, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 902 "compiler.tab.cc"
    break;

  case 24:
#line 212 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::NonEqual, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 910 "compiler.tab.cc"
    break;

  case 25:
#line 216 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 916 "compiler.tab.cc"
    break;

  case 26:
#line 220 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Plus, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope));
}
#line 924 "compiler.tab.cc"
    break;

  case 27:
#line 225 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Minus, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 932 "compiler.tab.cc"
    break;

  case 28:
#line 229 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 938 "compiler.tab.cc"
    break;

  case 29:
#line 234 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Multiply, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 946 "compiler.tab.cc"
    break;

  case 30:
#line 239 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new BinaryNode(yystack_[2].value.as < std::shared_ptr<ASTNode> > (), BinaryOp::Divide, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 954 "compiler.tab.cc"
    break;

  case 31:
#line 243 "compiler.y"
  { yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[0].value.as < std::shared_ptr<ASTNode> > (); }
#line 960 "compiler.tab.cc"
    break;

  case 32:
#line 247 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new UnaryNode(UnaryOp::Minus, yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)); 
}
#line 968 "compiler.tab.cc"
    break;

  case 33:
#line 252 "compiler.y"
{
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new InputNode(driver->currentScope));
    // std::cout << "аап";
}
#line 977 "compiler.tab.cc"
    break;

  case 34:
#line 258 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = yystack_[1].value.as < std::shared_ptr<ASTNode> > (); 
    std::cout << "Met {expr} " << std::endl; 
}
#line 986 "compiler.tab.cc"
    break;

  case 35:
#line 265 "compiler.y"
{ 
    yylhs.value.as < std::shared_ptr<ASTNode> > () = std::shared_ptr<ASTNode>(new NumNode(yystack_[0].value.as < int > (), driver->currentScope)); 
    std::cout << "num" << std::endl;  
}
#line 995 "compiler.tab.cc"
    break;

  case 36:
#line 271 "compiler.y"
{
    yylhs.value.as < std::shared_ptr<ASTNode> > () = createSetIdNode(yystack_[0].value.as < std::string > (), driver->currentScope);
    std::cout << "set id" << std::endl;
}
#line 1004 "compiler.tab.cc"
    break;

  case 37:
#line 277 "compiler.y"
{
    std::cout << "print";    
    driver->globalAstNode->create_child(std::shared_ptr<ASTNode>(new OutputNode(yystack_[0].value.as < std::shared_ptr<ASTNode> > (), driver->currentScope)));
}
#line 1013 "compiler.tab.cc"
    break;


#line 1017 "compiler.tab.cc"

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


  const signed char parser::yypact_ninf_ = -55;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      11,    33,    33,   -55,   -21,    -1,    33,   -55,    32,    11,
      11,   -55,   -55,    36,   -55,   -55,    55,    48,    57,   -55,
      45,   -55,   -55,    -7,    33,    33,   -55,    33,    -2,   -55,
      33,    33,   -55,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,   -55,   -55,   -16,    10,    43,   -55,    55,
      55,    48,    48,    48,    48,    48,    48,    57,    57,   -55,
     -55,    11,    11,   -55,   -55,    24,   -55,   -55,    11,   -55,
     -55
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,    33,     0,     0,     0,    35,    36,     0,
       2,     3,     9,     0,    13,    14,    18,    25,    28,    31,
       0,    36,    32,     0,     0,     0,    37,     0,     0,     4,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    34,     0,     0,     0,     5,    16,
      17,    21,    22,    19,    20,    24,    23,    27,    26,    29,
      30,     0,     0,    15,    10,    13,     8,    12,     0,     7,
      11
  };

  const signed char
  parser::yypgoto_[] =
  {
     -55,    41,   -10,   -55,    22,   -54,   -52,    51,    42,    44,
       0,   -55
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20
  };

  const signed char
  parser::yytable_[] =
  {
      29,    22,     1,    30,    31,    44,    26,    65,    66,     2,
      67,    24,    30,    31,    69,     1,    70,    61,    29,     3,
       4,     5,     2,     6,    23,     7,     8,     9,    48,    30,
      31,    25,     3,     4,     5,    27,     6,     1,     7,     8,
       9,    59,    60,    62,     2,    43,    45,    46,    68,    47,
      28,    64,    39,    40,     3,    30,    31,     0,     6,     0,
       7,    21,    30,    31,    41,    42,     0,    32,    33,    34,
      35,    36,    37,    38,    63,    51,    52,    53,    54,    55,
      56,    49,    50,    57,    58
  };

  const signed char
  parser::yycheck_[] =
  {
      10,     1,     4,    19,    20,    12,     6,    61,    62,    11,
      62,    32,    19,    20,    68,     4,    68,    33,    28,    21,
      22,    23,    11,    25,     2,    27,    28,    29,    30,    19,
      20,    32,    21,    22,    23,     3,    25,     4,    27,    28,
      29,    41,    42,    33,    11,     0,    24,    25,    24,    27,
       9,    61,     4,     5,    21,    19,    20,    -1,    25,    -1,
      27,    28,    19,    20,     7,     8,    -1,    31,    13,    14,
      15,    16,    17,    18,    31,    33,    34,    35,    36,    37,
      38,    30,    31,    39,    40
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,    11,    21,    22,    23,    25,    27,    28,    29,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    28,    44,    38,    32,    32,    44,     3,    35,    36,
      19,    20,    31,    13,    14,    15,    16,    17,    18,     4,
       5,     7,     8,     0,    12,    38,    38,    38,    30,    41,
      41,    42,    42,    42,    42,    42,    42,    43,    43,    44,
      44,    33,    33,    31,    36,    39,    39,    40,    24,    39,
      40
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    34,    45,    35,    35,    39,    39,    39,    39,    39,
      40,    40,    40,    36,    36,    37,    38,    38,    38,    41,
      41,    41,    41,    41,    41,    41,    42,    42,    42,    43,
      43,    43,    44,    44,    44,    44,    44,    44
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     3,     2,     7,     5,     1,
       5,     7,     5,     1,     1,     4,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     3,     1,     1,     2
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
  "ID_string", "'{'", "'}'", "';'", "'('", "')'", "$accept", "stmt_list",
  "stmt", "assign_stmt", "expr", "stmt_1", "stmt_2", "bool_expr",
  "arith_expr", "term", "primary_expr", "program", YY_NULLPTR
  };


  const short
  parser::yyrline_[] =
  {
       0,    93,    93,   105,   106,   109,   111,   113,   118,   123,
     138,   141,   144,   148,   148,   151,   173,   178,   183,   186,
     191,   196,   201,   206,   211,   216,   219,   224,   229,   233,
     238,   243,   246,   251,   257,   264,   270,   276
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
      32,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
#line 1402 "compiler.tab.cc"

#line 285 "compiler.y"

 


namespace yy {
    parser::token_type yylex(parser::semantic_type* yyval,
                             Driver* driver)
    {
        return driver->yylex(yyval);
    }
    void parser::error(const std::string&) {}
}
