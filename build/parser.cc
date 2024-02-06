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





#include "ParaCL.tab.hh"


// Unqualified %code blocks.
#line 18 "ParaCL.y"

    #include "ParaCLdriver.hpp"

    namespace yy {
        parser::token_type yylex(parser::semantic_type* yyval,
                                 Driver* driver);
    }
    struct VariableStore {
        std::unordered_map<std::string, int> variables;
    };

#line 57 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"


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
#line 129 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"


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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.move< int > (std::move (that.value));
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.copy< int > (YY_MOVE (that.value));
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.move< int > (YY_MOVE (s.value));
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.move< int > (YY_MOVE (that.value));
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.copy< int > (that.value);
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        value.move< int > (that.value);
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
      case 28: // ID
      case 37: // stmt_list
      case 38: // stmt
      case 39: // assign_stmt
      case 40: // expr
      case 41: // stmt_1
      case 42: // stmt_2
      case 43: // bool_expr
      case 44: // arith_expr
      case 45: // term
      case 46: // primary_expr
        yylhs.value.emplace< int > ();
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
#line 82 "ParaCL.y"
                   { std::cout << "Parsing complete!" << std::endl; }
#line 712 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 3:
#line 85 "ParaCL.y"
           { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 718 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 4:
#line 85 "ParaCL.y"
                  { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 724 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 5:
#line 89 "ParaCL.y"
                          { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 730 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 6:
#line 90 "ParaCL.y"
                      { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 736 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 7:
#line 92 "ParaCL.y"
        {
            if (yystack_[4].value.as < int > ()) 
            {
                yystack_[2].value.as < int > ();
            }
            else 
            {
                yystack_[0].value.as < int > ();
            }
            std::cout << "If-else stmt" << std::endl;
        }
#line 752 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 8:
#line 104 "ParaCL.y"
        {
            while (yystack_[2].value.as < int > ())
            {
                yystack_[0].value.as < int > ();
            }
            std::cout << "While stmt-1" << std::endl;
        }
#line 764 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 9:
#line 111 "ParaCL.y"
          { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 770 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 10:
#line 115 "ParaCL.y"
        {
            if (yystack_[2].value.as < int > ()) { yystack_[0].value.as < int > (); };
            std::cout << "If-stmt" << std::endl;
        }
#line 779 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 11:
#line 121 "ParaCL.y"
        {
            if (yystack_[4].value.as < int > ()) { yystack_[2].value.as < int > (); } else { yystack_[0].value.as < int > (); };
            std::cout << "If-else stmt" << std::endl;
        }
#line 788 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 12:
#line 127 "ParaCL.y"
        {
            while (yystack_[2].value.as < int > ()) { yystack_[0].value.as < int > (); };
            std::cout << "While-stmt" << std::endl;
        }
#line 797 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 13:
#line 133 "ParaCL.y"
      { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 803 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 14:
#line 133 "ParaCL.y"
               { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 809 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 15:
#line 137 "ParaCL.y"
                                   {
    std::cout << yystack_[1].value.as < int > () << " assigned for " << yystack_[3].value.as < int > () << std::endl;
    yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    std::cout << "Result: " << yylhs.value.as < int > () << std::endl;
}
#line 819 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 16:
#line 144 "ParaCL.y"
                         {
    yylhs.value.as < int > () = (yystack_[2].value.as < int > () && yystack_[0].value.as < int > ());
    std::cout << "Checking: " << yystack_[2].value.as < int > () << " vs " << yystack_[0].value.as < int > () << "; Result: " << yylhs.value.as < int > () << std::endl;
}
#line 828 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 17:
#line 149 "ParaCL.y"
                    {
    yylhs.value.as < int > () = (yystack_[2].value.as < int > () || yystack_[0].value.as < int > ());
    std::cout << "Checking: " << yystack_[2].value.as < int > () << " vs " << yystack_[0].value.as < int > () << "; Result: " << yylhs.value.as < int > () << std::endl;
}
#line 837 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 18:
#line 154 "ParaCL.y"
  { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 843 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 19:
#line 157 "ParaCL.y"
                                          {
    yylhs.value.as < int > () = (yystack_[2].value.as < int > () >= yystack_[0].value.as < int > ());
    std::cout << "Checking: " << yystack_[2].value.as < int > () << " vs " << yystack_[0].value.as < int > () << "; Result: " << yylhs.value.as < int > () << std::endl;
}
#line 852 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 20:
#line 162 "ParaCL.y"
                              {
    yylhs.value.as < int > () = (yystack_[2].value.as < int > () <= yystack_[0].value.as < int > ());
    std::cout << "Checking: " << yystack_[2].value.as < int > () << " vs " << yystack_[0].value.as < int > () << "; Result: " << yylhs.value.as < int > () << std::endl;
}
#line 861 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 21:
#line 167 "ParaCL.y"
                             {
    yylhs.value.as < int > () = (yystack_[2].value.as < int > () < yystack_[0].value.as < int > ());
    std::cout << "Checking: " << yystack_[2].value.as < int > () << " vs " << yystack_[0].value.as < int > () << "; Result: " << yylhs.value.as < int > () << std::endl;
}
#line 870 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 22:
#line 172 "ParaCL.y"
                                {
    yylhs.value.as < int > () = (yystack_[2].value.as < int > () > yystack_[0].value.as < int > ());
    std::cout << "Checking: " << yystack_[2].value.as < int > () << " vs " << yystack_[0].value.as < int > () << "; Result: " << yylhs.value.as < int > () << std::endl;
}
#line 879 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 23:
#line 177 "ParaCL.y"
             { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 885 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 24:
#line 180 "ParaCL.y"
                                 { yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > (); }
#line 891 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 25:
#line 182 "ParaCL.y"
                        { yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > (); }
#line 897 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 26:
#line 184 "ParaCL.y"
        { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 903 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 27:
#line 188 "ParaCL.y"
                                 { yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > (); }
#line 909 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 28:
#line 190 "ParaCL.y"
                           { yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > (); }
#line 915 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 29:
#line 192 "ParaCL.y"
               { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 921 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 30:
#line 195 "ParaCL.y"
                                 { yylhs.value.as < int > () = -yystack_[0].value.as < int > (); }
#line 927 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 31:
#line 197 "ParaCL.y"
                     { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 933 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 32:
#line 200 "ParaCL.y"
      { 
    yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    std::cout << "Встретили число со значением " << yystack_[0].value.as < int > () << "\n----------------------------\n" << std::endl; 
}
#line 942 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 33:
#line 205 "ParaCL.y"
     {
    yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    std::cout << "Встретили переменную со значением: " << yystack_[0].value.as < int > () << std::endl;
}
#line 951 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 34:
#line 211 "ParaCL.y"
                           {
    yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    std::cout << yystack_[1].value.as < int > () << std::endl;
}
#line 960 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;

  case 35:
#line 215 "ParaCL.y"
                                 {
    std::cout << "Введите значение для переменной: ";
    std::cin >> yylhs.value.as < int > ();
}
#line 969 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"
    break;


#line 973 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"

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


  const signed char parser::yypact_ninf_ = -56;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      21,    41,    41,     2,   -29,   -25,    14,   -56,    26,    21,
      21,   -56,   -56,    -4,   -56,   -56,    58,    71,    70,   -56,
      52,   -56,   -56,    37,     9,    41,    41,    41,    41,    -1,
     -56,   -56,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,   -56,   -56,    57,    -7,    19,    45,    -2,   -56,
      58,    58,    71,    71,    71,    71,    70,    70,   -56,   -56,
     -56,    21,    21,   -56,   -56,   -56,    59,   -56,   -56,    21,
     -56,   -56
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       2,     3,     9,     0,    13,    14,    18,    23,    26,    29,
       0,    33,    30,     0,     0,     0,     0,     0,     0,     0,
       4,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    31,     0,     0,     0,     0,     0,     5,
      16,    17,    21,    22,    19,    20,    25,    24,    27,    28,
      35,     0,     0,    34,    15,    10,    13,     8,    12,     0,
       7,    11
  };

  const signed char
  parser::yypgoto_[] =
  {
     -56,    75,   -10,   -56,     8,   -55,     1,    47,    24,    43,
       0,   -56
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
      30,    22,    31,     1,    64,    25,    66,    67,     2,    26,
      23,    24,    32,    33,    70,    32,    33,    32,    33,    30,
       3,     4,     5,    27,     6,     1,     7,     8,    61,    28,
       2,     9,    49,    45,    46,    47,    48,    44,    32,    33,
      58,    59,     3,     4,     5,     1,     6,    43,     7,     8,
       2,    65,    42,     9,    62,    63,    32,    33,    52,    53,
      54,    55,     3,    68,    32,    33,     6,    60,     7,    21,
      71,    34,    35,    36,    37,    38,    39,    40,    41,    50,
      51,    56,    57,    69,    29
  };

  const signed char
  parser::yycheck_[] =
  {
      10,     1,     6,     4,     6,    34,    61,    62,     9,    34,
       2,     9,    19,    20,    69,    19,    20,    19,    20,    29,
      21,    22,    23,     9,    25,     4,    27,    28,    35,     3,
       9,    32,    33,    25,    26,    27,    28,    28,    19,    20,
      40,    41,    21,    22,    23,     4,    25,    10,    27,    28,
       9,    61,     0,    32,    35,    10,    19,    20,    34,    35,
      36,    37,    21,    62,    19,    20,    25,    10,    27,    28,
      69,    13,    14,    15,    16,     4,     5,     7,     8,    32,
      33,    38,    39,    24,     9
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,     9,    21,    22,    23,    25,    27,    28,    32,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    28,    46,    40,     9,    34,    34,     9,     3,    37,
      38,     6,    19,    20,    13,    14,    15,    16,     4,     5,
       7,     8,     0,    10,    28,    40,    40,    40,    40,    33,
      43,    43,    44,    44,    44,    44,    45,    45,    46,    46,
      10,    35,    35,    10,     6,    38,    41,    41,    42,    24,
      41,    42
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    36,    47,    37,    37,    41,    41,    41,    41,    41,
      42,    42,    42,    38,    38,    39,    40,    40,    40,    43,
      43,    43,    43,    43,    44,    44,    44,    45,    45,    45,
      46,    46,    46,    46,    46,    46
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     3,     2,     7,     5,     1,
       5,     7,     5,     1,     1,     4,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     3,     1,     1,     4,     4
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
  "\"if\"", "\"while\"", "\"else\"", "\"print\"", "ERR", "NUM", "ID",
  "NOT_EQUAL", "LESS_EQUAL", "GREATER_EQUAL", "'{'", "'}'", "'('", "')'",
  "$accept", "stmt_list", "stmt", "assign_stmt", "expr", "stmt_1",
  "stmt_2", "bool_expr", "arith_expr", "term", "primary_expr", "program", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    82,    82,    85,    85,    89,    90,    91,   103,   111,
     114,   120,   126,   133,   133,   137,   144,   149,   154,   157,
     162,   167,   172,   177,   180,   182,   184,   188,   190,   192,
     195,   197,   200,   205,   211,   215
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
      34,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
    };
    const int user_token_number_max_ = 286;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 1358 "/home/masha/code_projects/MIPT_Ilab/ParaCL/ParaCL/build/parser.cc"

#line 222 "ParaCL.y"


namespace yy {
    parser::token_type yylex(parser::semantic_type* yyval,
                             Driver* driver)
    {
        return driver->yylex(yyval);
    }
    void parser::error(const std::string&) {}
}
