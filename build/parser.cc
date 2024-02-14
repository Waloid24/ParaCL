// A Bison parser, made by GNU Bison 3.8.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "grammar.tab.hh"


// Unqualified %code blocks.
#line 20 "generators/parser.y"

    #include "../include/driver.hpp"

    using namespace nodes;

    namespace yy {

        parser::token_type yylex(parser::semantic_type* yylval, 
                                 parser::location_type* yyloc, Driver* driver);
    
    }


#line 60 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 152 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"

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
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        value.copy< nodes::Base_node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        value.move< nodes::Base_node* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
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

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        value.YY_MOVE_OR_COPY< nodes::Base_node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
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
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        value.move< nodes::Base_node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        value.copy< nodes::Base_node* > (that.value);
        break;

      case symbol_kind::S_ID: // ID
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER: // INTEGER
        value.move< int > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        value.move< nodes::Base_node* > (that.value);
        break;

      case symbol_kind::S_ID: // ID
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
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
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
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

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_stms: // stms
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_open_scope: // open_scope
      case symbol_kind::S_close_scope: // close_scope
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_open_statement: // open_statement
      case symbol_kind::S_closed_statement: // closed_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_lval: // lval
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_boolean: // boolean
      case symbol_kind::S_arithmetic: // arithmetic
      case symbol_kind::S_term: // term
      case symbol_kind::S_primary: // primary
        yylhs.value.emplace< nodes::Base_node* > ();
        break;

      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: stms
#line 103 "generators/parser.y"
                                        {
                                            driver->process();
                                        }
#line 826 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 3: // stms: statement
#line 108 "generators/parser.y"
                                        {
                                            driver->add_branch(yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 834 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 4: // stms: stms statement
#line 111 "generators/parser.y"
                                        {
                                            driver->add_branch(yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 842 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 5: // scope: open_scope stms close_scope
#line 116 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 850 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 6: // open_scope: "{"
#line 121 "generators/parser.y"
                                        {
                                            driver->cur_scope_ = new Scope_node(driver->cur_scope_);
                                        }
#line 858 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 7: // close_scope: "}"
#line 126 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = driver->cur_scope_;
                                            driver->cur_scope_ = driver->cur_scope_->reset_scope();
                                        }
#line 867 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 8: // statement: open_statement
#line 132 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 875 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 9: // statement: closed_statement
#line 135 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 883 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 10: // open_statement: "if" "(" expression ")" statement
#line 141 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new If_node(yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 891 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 11: // open_statement: "if" "(" expression ")" closed_statement "else" open_statement
#line 145 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new If_node(yystack_[4].value.as < nodes::Base_node* > (), yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 899 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 12: // open_statement: "while" "(" expression ")" open_statement
#line 149 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new While_node(yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 907 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 13: // closed_statement: simple_statement
#line 154 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 915 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 14: // closed_statement: scope
#line 157 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 923 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 15: // closed_statement: "if" "(" expression ")" closed_statement "else" closed_statement
#line 161 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new If_node(yystack_[4].value.as < nodes::Base_node* > (), yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 931 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 16: // closed_statement: "while" "(" expression ")" closed_statement
#line 165 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new While_node(yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 939 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 17: // simple_statement: assign
#line 170 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 947 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 18: // simple_statement: expression ";"
#line 173 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[1].value.as < nodes::Base_node* > ();
                                        }
#line 955 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 19: // simple_statement: "print" expression ";"
#line 177 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Func_node(func_type::OUTPUT, yystack_[1].value.as < nodes::Base_node* > ());
                                        }
#line 963 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 20: // assign: lval "=" "?" ";"
#line 183 "generators/parser.y"
                                        {
                                            Func_node* f_node = new Func_node(func_type::INPUT);
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::ASSIGN, yystack_[3].value.as < nodes::Base_node* > (), f_node);
                                        }
#line 972 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 21: // assign: lval "=" expression ";"
#line 187 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::ASSIGN, yystack_[3].value.as < nodes::Base_node* > (), yystack_[1].value.as < nodes::Base_node* > ());
                                        }
#line 980 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 22: // lval: ID
#line 192 "generators/parser.y"
                                        {
                                            Var* var = driver->lookup(yystack_[0].value.as < std::string > ());
                                            if (var == nullptr)
                                            {
                                                var = new Var{};
                                                driver->emplace(yystack_[0].value.as < std::string > (), var);
                                            }

                                            yylhs.value.as < nodes::Base_node* > () = new Id_node(yystack_[0].value.as < std::string > (), var);
                                        }
#line 995 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 23: // expression: expression "&&" boolean
#line 204 "generators/parser.y"
                                        {   
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::AND, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1003 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 24: // expression: expression "||" boolean
#line 207 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::OR, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1011 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 25: // expression: boolean
#line 210 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 1019 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 26: // boolean: boolean "==" arithmetic
#line 215 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::EQUAL, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1027 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 27: // boolean: boolean "!=" arithmetic
#line 218 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::NOT_EQUAL, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1035 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 28: // boolean: boolean ">" arithmetic
#line 221 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::GREATER, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1043 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 29: // boolean: boolean ">=" arithmetic
#line 224 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::GREATER_EQUAL, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1051 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 30: // boolean: boolean "<" arithmetic
#line 227 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::LESS, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1059 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 31: // boolean: boolean "<=" arithmetic
#line 230 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::LESS_EQUAL, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1067 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 32: // boolean: arithmetic
#line 233 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 1075 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 33: // arithmetic: arithmetic "+" term
#line 238 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::PLUS, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1083 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 34: // arithmetic: arithmetic "-" term
#line 241 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::MINUS, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1091 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 35: // arithmetic: term
#line 244 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 1099 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 36: // term: term "*" primary
#line 249 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::MUL, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1107 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 37: // term: term "/" primary
#line 252 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Bin_op_node(bin_op_type::DIV, yystack_[2].value.as < nodes::Base_node* > (), yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1115 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 38: // term: primary
#line 255 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[0].value.as < nodes::Base_node* > ();
                                        }
#line 1123 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 39: // primary: "-" primary
#line 260 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Un_op_node(un_op_type::U_MINUS, yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1131 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 40: // primary: "!" primary
#line 263 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > ()= new Un_op_node(un_op_type::NOT, yystack_[0].value.as < nodes::Base_node* > ());
                                        }
#line 1139 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 41: // primary: "(" expression ")"
#line 266 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = yystack_[1].value.as < nodes::Base_node* > ();
                                        }
#line 1147 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 42: // primary: INTEGER
#line 269 "generators/parser.y"
                                        {
                                            yylhs.value.as < nodes::Base_node* > () = new Integer_node(yystack_[0].value.as < int > ()); 
                                        }
#line 1155 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;

  case 43: // primary: ID
#line 272 "generators/parser.y"
                                        {
                                            Var* var = driver->lookup(yystack_[0].value.as < std::string > ());
                                            if (var == nullptr)
                                            {
                                                driver->report_name_error(yystack_[0].location, yystack_[0].value.as < std::string > ());
                                            }
                                            yylhs.value.as < nodes::Base_node* > () = new Id_node(yystack_[0].value.as < std::string > (), var);
                                        }
#line 1168 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"
    break;


#line 1172 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"

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
        context yyctx (*this, yyla);
        report_syntax_error (yyctx);
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
    YY_STACK_PRINT ();
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
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "if", "else", "while", "print",
  "?", "(", ")", "{", "}", ";", "<", "<=", ">", ">=", "==", "!=", "&&",
  "||", "!", "=", "-", "+", "*", "/", "ERR", "INTEGER", "ID", "$accept",
  "program", "stms", "scope", "open_scope", "close_scope", "statement",
  "open_statement", "closed_statement", "simple_statement", "assign",
  "lval", "expression", "boolean", "arithmetic", "term", "primary", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }








  const signed char parser::yypact_ninf_ = -66;

  const signed char parser::yytable_ninf_ = -23;

  const signed char
  parser::yypact_[] =
  {
      41,     7,    13,    31,    31,   -66,    31,    31,   -66,   -14,
      24,    41,   -66,    41,   -66,   -66,   -66,   -66,   -66,    12,
      53,    70,     9,    51,   -66,    31,    31,   -66,    59,    21,
     -66,   -66,   -66,   -66,     8,    -1,   -66,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    36,
      48,   -66,   -66,   -66,   -66,    26,    62,    70,    70,     9,
       9,     9,     9,     9,     9,    51,    51,   -66,   -66,    41,
      41,   -66,   -66,   -66,    44,   -66,   -66,    41,   -66,   -66
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     6,     0,     0,    42,    43,
       0,     2,    14,     0,     3,     8,     9,    13,    17,     0,
       0,    25,    32,    35,    38,     0,     0,    43,     0,     0,
      40,    39,     1,     4,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    41,     7,     5,     0,     0,    23,    24,    30,
      31,    28,    29,    26,    27,    34,    33,    36,    37,     0,
       0,    20,    21,    10,     9,    12,    16,     0,    11,    15
  };

  const signed char
  parser::yypgoto_[] =
  {
     -66,   -66,    37,   -66,   -66,   -66,   -11,   -65,   -60,   -66,
     -66,   -66,     0,    58,    50,    52,    -5
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    10,    11,    12,    13,    54,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24
  };

  const signed char
  parser::yytable_[] =
  {
      33,    30,    31,    28,    29,    75,    55,     4,   -22,    74,
      76,     1,    78,     2,     3,    25,     4,    79,     5,    53,
       6,    26,     7,    33,    32,    49,    50,     8,    27,     6,
      52,     7,    45,    46,    35,    56,     8,     9,    71,     4,
      37,    38,    67,    68,     1,    69,     2,     3,    77,     4,
      34,     5,     6,     0,     7,    37,    38,    70,    73,     8,
      27,     0,     6,     0,     7,    36,     0,    37,    38,     8,
       9,    51,    37,    38,    72,     0,    47,    48,    37,    38,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    59,
      60,    61,    62,    63,    64,    57,    58,    65,    66
  };

  const signed char
  parser::yycheck_[] =
  {
      11,     6,     7,     3,     4,    70,     7,     8,    22,    69,
      70,     3,    77,     5,     6,     8,     8,    77,    10,    11,
      21,     8,    23,    34,     0,    25,    26,    28,    29,    21,
       9,    23,    23,    24,    22,    35,    28,    29,    12,     8,
      19,    20,    47,    48,     3,     9,     5,     6,     4,     8,
      13,    10,    21,    -1,    23,    19,    20,     9,    69,    28,
      29,    -1,    21,    -1,    23,    12,    -1,    19,    20,    28,
      29,    12,    19,    20,    12,    -1,    25,    26,    19,    20,
      -1,    19,    20,    13,    14,    15,    16,    17,    18,    39,
      40,    41,    42,    43,    44,    37,    38,    45,    46
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     5,     6,     8,    10,    21,    23,    28,    29,
      31,    32,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     8,     8,    29,    42,    42,
      46,    46,     0,    36,    32,    22,    12,    19,    20,    13,
      14,    15,    16,    17,    18,    23,    24,    25,    26,    42,
      42,    12,     9,    11,    35,     7,    42,    43,    43,    44,
      44,    44,    44,    44,    44,    45,    45,    46,    46,     9,
       9,    12,    12,    36,    38,    37,    38,     4,    37,    38
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    30,    31,    32,    32,    33,    34,    35,    36,    36,
      37,    37,    37,    38,    38,    38,    38,    39,    39,    39,
      40,    40,    41,    42,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    45,    45,    45,    46,
      46,    46,    46,    46
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     3,     1,     1,     1,     1,
       5,     7,     5,     1,     1,     7,     5,     1,     2,     3,
       4,     4,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     2,
       2,     3,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   103,   103,   108,   111,   116,   121,   126,   132,   135,
     140,   144,   148,   154,   157,   160,   164,   170,   173,   176,
     183,   187,   192,   204,   207,   210,   215,   218,   221,   224,
     227,   230,   233,   238,   241,   244,   249,   252,   255,   260,
     263,   266,   269,   272
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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

  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      25,    26,    27,    28,    29
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1612 "/home/andrey/Desktop/DREC/ilab/ParaCL/build/parser.cc"

#line 282 "generators/parser.y"


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
