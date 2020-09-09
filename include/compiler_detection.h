
// This is a generated file. Do not edit!

#ifndef FEATURE_COMPILER_DETECTION_H
#define FEATURE_COMPILER_DETECTION_H

#define FEATURE_DEC(X) (X)
#define FEATURE_HEX(X) ( \
    ((X)>>28 & 0xF) * 10000000 + \
    ((X)>>24 & 0xF) *  1000000 + \
    ((X)>>20 & 0xF) *   100000 + \
    ((X)>>16 & 0xF) *    10000 + \
    ((X)>>12 & 0xF) *     1000 + \
    ((X)>>8  & 0xF) *      100 + \
    ((X)>>4  & 0xF) *       10 + \
    ((X)     & 0xF) \
    )

#ifdef __cplusplus
# define FEATURE_COMPILER_IS_Comeau 0
# define FEATURE_COMPILER_IS_Intel 0
# define FEATURE_COMPILER_IS_PathScale 0
# define FEATURE_COMPILER_IS_Embarcadero 0
# define FEATURE_COMPILER_IS_Borland 0
# define FEATURE_COMPILER_IS_Watcom 0
# define FEATURE_COMPILER_IS_OpenWatcom 0
# define FEATURE_COMPILER_IS_SunPro 0
# define FEATURE_COMPILER_IS_HP 0
# define FEATURE_COMPILER_IS_Compaq 0
# define FEATURE_COMPILER_IS_zOS 0
# define FEATURE_COMPILER_IS_XLClang 0
# define FEATURE_COMPILER_IS_XL 0
# define FEATURE_COMPILER_IS_VisualAge 0
# define FEATURE_COMPILER_IS_PGI 0
# define FEATURE_COMPILER_IS_Cray 0
# define FEATURE_COMPILER_IS_TI 0
# define FEATURE_COMPILER_IS_Fujitsu 0
# define FEATURE_COMPILER_IS_GHS 0
# define FEATURE_COMPILER_IS_SCO 0
# define FEATURE_COMPILER_IS_ARMCC 0
# define FEATURE_COMPILER_IS_AppleClang 0
# define FEATURE_COMPILER_IS_ARMClang 0
# define FEATURE_COMPILER_IS_Clang 0
# define FEATURE_COMPILER_IS_GNU 0
# define FEATURE_COMPILER_IS_MSVC 0
# define FEATURE_COMPILER_IS_ADSP 0
# define FEATURE_COMPILER_IS_IAR 0
# define FEATURE_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef FEATURE_COMPILER_IS_Comeau
# define FEATURE_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef FEATURE_COMPILER_IS_Intel
# define FEATURE_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef FEATURE_COMPILER_IS_PathScale
# define FEATURE_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef FEATURE_COMPILER_IS_Embarcadero
# define FEATURE_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef FEATURE_COMPILER_IS_Borland
# define FEATURE_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef FEATURE_COMPILER_IS_Watcom
# define FEATURE_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef FEATURE_COMPILER_IS_OpenWatcom
# define FEATURE_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef FEATURE_COMPILER_IS_SunPro
# define FEATURE_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef FEATURE_COMPILER_IS_HP
# define FEATURE_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef FEATURE_COMPILER_IS_Compaq
# define FEATURE_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef FEATURE_COMPILER_IS_zOS
# define FEATURE_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef FEATURE_COMPILER_IS_XLClang
# define FEATURE_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef FEATURE_COMPILER_IS_XL
# define FEATURE_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef FEATURE_COMPILER_IS_VisualAge
# define FEATURE_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef FEATURE_COMPILER_IS_PGI
# define FEATURE_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef FEATURE_COMPILER_IS_Cray
# define FEATURE_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef FEATURE_COMPILER_IS_TI
# define FEATURE_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef FEATURE_COMPILER_IS_Fujitsu
# define FEATURE_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef FEATURE_COMPILER_IS_GHS
# define FEATURE_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef FEATURE_COMPILER_IS_SCO
# define FEATURE_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef FEATURE_COMPILER_IS_ARMCC
# define FEATURE_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef FEATURE_COMPILER_IS_AppleClang
# define FEATURE_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef FEATURE_COMPILER_IS_ARMClang
# define FEATURE_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef FEATURE_COMPILER_IS_Clang
# define FEATURE_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef FEATURE_COMPILER_IS_GNU
# define FEATURE_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef FEATURE_COMPILER_IS_MSVC
# define FEATURE_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef FEATURE_COMPILER_IS_ADSP
# define FEATURE_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef FEATURE_COMPILER_IS_IAR
# define FEATURE_COMPILER_IS_IAR 1


#endif

#  if FEATURE_COMPILER_IS_AppleClang

# define FEATURE_COMPILER_VERSION_MAJOR FEATURE_DEC(__clang_major__)
# define FEATURE_COMPILER_VERSION_MINOR FEATURE_DEC(__clang_minor__)
# define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define FEATURE_SIMULATE_VERSION_MAJOR FEATURE_DEC(_MSC_VER / 100)
#  define FEATURE_SIMULATE_VERSION_MINOR FEATURE_DEC(_MSC_VER % 100)
# endif
# define FEATURE_COMPILER_VERSION_TWEAK FEATURE_DEC(__apple_build_version__)

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_aggregate_nsdmi)
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alias_templates)
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define FEATURE_COMPILER_CXX_ALIGNAS 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define FEATURE_COMPILER_CXX_ALIGNOF 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_attributes)
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 501 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_auto_type)
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_binary_literals)
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_constexpr)
#      define FEATURE_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_contextual_conversions)
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_decltype_incomplete_return_types)
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_decltype)
#      define FEATURE_COMPILER_CXX_DECLTYPE 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 501 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_default_function_template_args)
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_defaulted_functions)
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_defaulted_functions)
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_delegating_constructors)
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_deleted_functions)
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 501 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 1
#    else
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_explicit_conversions)
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_override_control)
#      define FEATURE_COMPILER_CXX_FINAL 1
#    else
#      define FEATURE_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 1
#    else
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_generalized_initializers)
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 501 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_inheriting_constructors)
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 1
#    else
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_lambdas)
#      define FEATURE_COMPILER_CXX_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_init_captures)
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_local_type_template_args)
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_noexcept)
#      define FEATURE_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FEATURE_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_nonstatic_member_init)
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 1
#    else
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_nullptr)
#      define FEATURE_COMPILER_CXX_NULLPTR 1
#    else
#      define FEATURE_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_override_control)
#      define FEATURE_COMPILER_CXX_OVERRIDE 1
#    else
#      define FEATURE_COMPILER_CXX_OVERRIDE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_range_for)
#      define FEATURE_COMPILER_CXX_RANGE_FOR 1
#    else
#      define FEATURE_COMPILER_CXX_RANGE_FOR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_raw_string_literals)
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_reference_qualified_functions)
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_relaxed_constexpr)
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_return_type_deduction)
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 1
#    else
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 1
#    else
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_rvalue_references)
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 1
#    else
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_static_assert)
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_strong_enums)
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 1
#    else
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_thread_local)
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_trailing_return)
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_unicode_literals)
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_generalized_initializers)
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 1
#    else
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_unrestricted_unions)
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 1
#    else
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_user_literals)
#      define FEATURE_COMPILER_CXX_USER_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_USER_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_variable_templates)
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_variadic_templates)
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 199711L
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 1
#    else
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 0
#    endif

#  elif FEATURE_COMPILER_IS_Clang

# define FEATURE_COMPILER_VERSION_MAJOR FEATURE_DEC(__clang_major__)
# define FEATURE_COMPILER_VERSION_MINOR FEATURE_DEC(__clang_minor__)
# define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define FEATURE_SIMULATE_VERSION_MAJOR FEATURE_DEC(_MSC_VER / 100)
#  define FEATURE_SIMULATE_VERSION_MINOR FEATURE_DEC(_MSC_VER % 100)
# endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_aggregate_nsdmi)
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alias_templates)
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alignas)
#      define FEATURE_COMPILER_CXX_ALIGNAS 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alignas)
#      define FEATURE_COMPILER_CXX_ALIGNOF 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_attributes)
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_auto_type)
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_binary_literals)
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_constexpr)
#      define FEATURE_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_contextual_conversions)
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_decltype_incomplete_return_types)
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_decltype)
#      define FEATURE_COMPILER_CXX_DECLTYPE 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_default_function_template_args)
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_defaulted_functions)
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_defaulted_functions)
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_delegating_constructors)
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_deleted_functions)
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 1
#    else
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_explicit_conversions)
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_override_control)
#      define FEATURE_COMPILER_CXX_FINAL 1
#    else
#      define FEATURE_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 1
#    else
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_generalized_initializers)
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_inheriting_constructors)
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 1
#    else
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_lambdas)
#      define FEATURE_COMPILER_CXX_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_init_captures)
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_local_type_template_args)
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_noexcept)
#      define FEATURE_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FEATURE_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_nonstatic_member_init)
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 1
#    else
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_nullptr)
#      define FEATURE_COMPILER_CXX_NULLPTR 1
#    else
#      define FEATURE_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_override_control)
#      define FEATURE_COMPILER_CXX_OVERRIDE 1
#    else
#      define FEATURE_COMPILER_CXX_OVERRIDE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_range_for)
#      define FEATURE_COMPILER_CXX_RANGE_FOR 1
#    else
#      define FEATURE_COMPILER_CXX_RANGE_FOR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_raw_string_literals)
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_reference_qualified_functions)
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_relaxed_constexpr)
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_return_type_deduction)
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 1
#    else
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 1
#    else
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_rvalue_references)
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 1
#    else
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_static_assert)
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_strong_enums)
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 1
#    else
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_thread_local)
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_trailing_return)
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_unicode_literals)
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_generalized_initializers)
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 1
#    else
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_unrestricted_unions)
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 1
#    else
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_user_literals)
#      define FEATURE_COMPILER_CXX_USER_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_USER_LITERALS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_variable_templates)
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_variadic_templates)
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __cplusplus >= 199711L
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 1
#    else
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 0
#    endif

#  elif FEATURE_COMPILER_IS_GNU

# if defined(__GNUC__)
#  define FEATURE_COMPILER_VERSION_MAJOR FEATURE_DEC(__GNUC__)
# else
#  define FEATURE_COMPILER_VERSION_MAJOR FEATURE_DEC(__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define FEATURE_COMPILER_VERSION_MINOR FEATURE_DEC(__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(__GNUC_PATCHLEVEL__)
# endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 500 && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ALIGNAS 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNAS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ALIGNOF 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNOF 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 0
#    endif

#    if ((__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) >= 40801) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DECLTYPE 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 1
#    else
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 405 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_FINAL 1
#    else
#      define FEATURE_COMPILER_CXX_FINAL 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 1
#    else
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 1
#    else
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 405 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDAS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 405 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FEATURE_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 1
#    else
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_NULLPTR 1
#    else
#      define FEATURE_COMPILER_CXX_NULLPTR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_OVERRIDE 1
#    else
#      define FEATURE_COMPILER_CXX_OVERRIDE 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RANGE_FOR 1
#    else
#      define FEATURE_COMPILER_CXX_RANGE_FOR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 405 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 0
#    endif

#    if ((__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) >= 40801) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 500 && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 1
#    else
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 1
#    else
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 1
#    else
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 1
#    else
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 1
#    else
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 1
#    else
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_USER_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_USER_LITERALS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 500 && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && __cplusplus
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 1
#    else
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 0
#    endif

#  elif FEATURE_COMPILER_IS_MSVC

  /* _MSC_VER = VVRR */
# define FEATURE_COMPILER_VERSION_MAJOR FEATURE_DEC(_MSC_VER / 100)
# define FEATURE_COMPILER_VERSION_MINOR FEATURE_DEC(_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define FEATURE_COMPILER_VERSION_TWEAK FEATURE_DEC(_MSC_BUILD)
# endif

#    if _MSC_FULL_VER >= 190024406
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_ALIGNAS 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNAS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_ALIGNOF 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNOF 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 0
#    endif

#    if _MSC_VER >= 1911
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_DECLTYPE 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 1
#    else
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 0
#    endif

#    if _MSC_VER >= 1700
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 0
#    endif

#    if _MSC_VER >= 1700
#      define FEATURE_COMPILER_CXX_FINAL 1
#    else
#      define FEATURE_COMPILER_CXX_FINAL 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 1
#    else
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 0
#    endif

#    if _MSC_FULL_VER >= 180030723
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 1
#    else
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDAS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FEATURE_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 1
#    else
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_NULLPTR 1
#    else
#      define FEATURE_COMPILER_CXX_NULLPTR 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_OVERRIDE 1
#    else
#      define FEATURE_COMPILER_CXX_OVERRIDE 0
#    endif

#    if _MSC_VER >= 1700
#      define FEATURE_COMPILER_CXX_RANGE_FOR 1
#    else
#      define FEATURE_COMPILER_CXX_RANGE_FOR 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 0
#    endif

#    if _MSC_VER >= 1911
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 1
#    else
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 1
#    else
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 1
#    else
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if _MSC_VER >= 1700
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 1
#    else
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 1
#    else
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 1
#    else
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 0
#    endif

#    if _MSC_VER >= 1900
#      define FEATURE_COMPILER_CXX_USER_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_USER_LITERALS 0
#    endif

#    if _MSC_FULL_VER >= 190023918
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 0
#    endif

#    if _MSC_VER >= 1800
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 0
#    endif

#    if _MSC_VER >= 1600
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 1
#    else
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 0
#    endif

#  elif FEATURE_COMPILER_IS_SunPro

# if __SUNPRO_CC >= 0x5100
   /* __SUNPRO_CC = 0xVRRP */
#  define FEATURE_COMPILER_VERSION_MAJOR FEATURE_HEX(__SUNPRO_CC>>12)
#  define FEATURE_COMPILER_VERSION_MINOR FEATURE_HEX(__SUNPRO_CC>>4 & 0xFF)
#  define FEATURE_COMPILER_VERSION_PATCH FEATURE_HEX(__SUNPRO_CC    & 0xF)
# else
   /* __SUNPRO_CC = 0xVRP */
#  define FEATURE_COMPILER_VERSION_MAJOR FEATURE_HEX(__SUNPRO_CC>>8)
#  define FEATURE_COMPILER_VERSION_MINOR FEATURE_HEX(__SUNPRO_CC>>4 & 0xF)
#  define FEATURE_COMPILER_VERSION_PATCH FEATURE_HEX(__SUNPRO_CC    & 0xF)
# endif

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ALIGNAS 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNAS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ALIGNOF 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNOF 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 0
#    endif

#    define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 0
#    endif

#    if (__SUNPRO_CC >= 0x5140) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_CONSTEXPR 0
#    endif

#    define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 0

#    define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 0

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DECLTYPE 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE 0
#    endif

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 1
#    else
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_FINAL 1
#    else
#      define FEATURE_COMPILER_CXX_FINAL 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 1
#    else
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 0
#    endif

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 1
#    else
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDAS 0
#    endif

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FEATURE_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 1
#    else
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_NULLPTR 1
#    else
#      define FEATURE_COMPILER_CXX_NULLPTR 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_OVERRIDE 1
#    else
#      define FEATURE_COMPILER_CXX_OVERRIDE 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_RANGE_FOR 1
#    else
#      define FEATURE_COMPILER_CXX_RANGE_FOR 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 0
#    endif

#    if (__SUNPRO_CC >= 0x5140) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 0
#    endif

#    define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 0

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 1
#    else
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 1
#    else
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 1
#    else
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 1
#    else
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 1
#    else
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 1
#    else
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 0
#    endif

#    define FEATURE_COMPILER_CXX_USER_LITERALS 0

#    if (__SUNPRO_CC >= 0x5150) && __cplusplus >= 201402L
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 0
#    endif

#    if (__SUNPRO_CC >= 0x5130) && __cplusplus >= 201103L
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 0
#    endif

#    if __SUNPRO_CC >= 0x5130 && __cplusplus
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 1
#    else
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 0
#    endif

#  elif FEATURE_COMPILER_IS_Intel

  /* __INTEL_COMPILER = VRP */
# define FEATURE_COMPILER_VERSION_MAJOR FEATURE_DEC(__INTEL_COMPILER/100)
# define FEATURE_COMPILER_VERSION_MINOR FEATURE_DEC(__INTEL_COMPILER/10 % 10)
# if defined(__INTEL_COMPILER_UPDATE)
#  define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(__INTEL_COMPILER_UPDATE)
# else
#  define FEATURE_COMPILER_VERSION_PATCH FEATURE_DEC(__INTEL_COMPILER   % 10)
# endif
# if defined(__INTEL_COMPILER_BUILD_DATE)
  /* __INTEL_COMPILER_BUILD_DATE = YYYYMMDD */
#  define FEATURE_COMPILER_VERSION_TWEAK FEATURE_DEC(__INTEL_COMPILER_BUILD_DATE)
# endif
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define FEATURE_SIMULATE_VERSION_MAJOR FEATURE_DEC(_MSC_VER / 100)
#  define FEATURE_SIMULATE_VERSION_MINOR FEATURE_DEC(_MSC_VER % 100)
# endif
# if defined(__GNUC__)
#  define FEATURE_SIMULATE_VERSION_MAJOR FEATURE_DEC(__GNUC__)
# elif defined(__GNUG__)
#  define FEATURE_SIMULATE_VERSION_MAJOR FEATURE_DEC(__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define FEATURE_SIMULATE_VERSION_MINOR FEATURE_DEC(__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define FEATURE_SIMULATE_VERSION_PATCH FEATURE_DEC(__GNUC_PATCHLEVEL__)
# endif

#    if __INTEL_COMPILER >= 1600 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_AGGREGATE_DEFAULT_INITIALIZERS 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_ALIAS_TEMPLATES 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_ALIGNAS 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNAS 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_ALIGNOF 1
#    else
#      define FEATURE_COMPILER_CXX_ALIGNOF 0
#    endif

#    if (__cpp_attributes >= 200809 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTES 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_AUTO_TYPE 0
#    endif

#    if __cpp_binary_literals >= 201304 || __INTEL_COMPILER >= 1210
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_BINARY_LITERALS 0
#    endif

#    if __cpp_constexpr >= 200704 || __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if __INTEL_COMPILER >= 1600 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_CONTEXTUAL_CONVERSIONS 0
#    endif

#    if ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__)) && (__INTEL_COMPILER > 1400 || (__INTEL_COMPILER == 1400 && __INTEL_COMPILER_UPDATE >= 2)) && !defined(_MSC_VER)
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_INCOMPLETE_RETURN_TYPES 0
#    endif

#    if __cpp_decltype >= 200707 || __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DECLTYPE 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE 0
#    endif

#    if __cpp_decltype_auto >= 201304 || __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 1
#    else
#      define FEATURE_COMPILER_CXX_DECLTYPE_AUTO 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULT_FUNCTION_TEMPLATE_ARGS 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_FUNCTIONS 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_DEFAULTED_MOVE_INITIALIZERS 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_DELEGATING_CONSTRUCTORS 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if __INTEL_COMPILER >= 1600 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 1
#    else
#      define FEATURE_COMPILER_CXX_DIGIT_SEPARATORS 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_ENUM_FORWARD_DECLARATIONS 0
#    endif

#    if __INTEL_COMPILER >= 1300 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXPLICIT_CONVERSIONS 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 1
#    else
#      define FEATURE_COMPILER_CXX_EXTENDED_FRIEND_DECLARATIONS 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_EXTERN_TEMPLATES 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_FINAL 1
#    else
#      define FEATURE_COMPILER_CXX_FINAL 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 1
#    else
#      define FEATURE_COMPILER_CXX_FUNC_IDENTIFIER 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERALIZED_INITIALIZERS 0
#    endif

#    if __cpp_generic_lambdas >= 201304
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_GENERIC_LAMBDAS 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 1
#    else
#      define FEATURE_COMPILER_CXX_INHERITING_CONSTRUCTORS 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 1
#    else
#      define FEATURE_COMPILER_CXX_INLINE_NAMESPACES 0
#    endif

#    if (__cpp_lambdas >= 200907 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_LAMBDAS 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDAS 0
#    endif

#    if (__cpp_init_captures >= 201304 || __INTEL_COMPILER >= 1500) && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 1
#    else
#      define FEATURE_COMPILER_CXX_LAMBDA_INIT_CAPTURES 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 1
#    else
#      define FEATURE_COMPILER_CXX_LOCAL_TYPE_TEMPLATE_ARGS 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 1
#    else
#      define FEATURE_COMPILER_CXX_LONG_LONG_TYPE 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_NOEXCEPT 1
#    else
#      define FEATURE_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 1
#    else
#      define FEATURE_COMPILER_CXX_NONSTATIC_MEMBER_INIT 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_NULLPTR 1
#    else
#      define FEATURE_COMPILER_CXX_NULLPTR 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_OVERRIDE 1
#    else
#      define FEATURE_COMPILER_CXX_OVERRIDE 0
#    endif

#    if __INTEL_COMPILER >= 1300 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RANGE_FOR 1
#    else
#      define FEATURE_COMPILER_CXX_RANGE_FOR 0
#    endif

#    if __cpp_raw_strings >= 200710 || __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_RAW_STRING_LITERALS 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 1
#    else
#      define FEATURE_COMPILER_CXX_REFERENCE_QUALIFIED_FUNCTIONS 0
#    endif

#    if __cpp_constexpr >= 201304 || (__INTEL_COMPILER >= 1700 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) ) && !defined(_MSC_VER))
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 1
#    else
#      define FEATURE_COMPILER_CXX_RELAXED_CONSTEXPR 0
#    endif

#    if __cpp_return_type_deduction >= 201304 || __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 1
#    else
#      define FEATURE_COMPILER_CXX_RETURN_TYPE_DEDUCTION 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 1
#    else
#      define FEATURE_COMPILER_CXX_RIGHT_ANGLE_BRACKETS 0
#    endif

#    if (__cpp_rvalue_references >= 200610 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 1
#    else
#      define FEATURE_COMPILER_CXX_RVALUE_REFERENCES 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define FEATURE_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if (__cpp_static_assert >= 200410 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define FEATURE_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 1
#    else
#      define FEATURE_COMPILER_CXX_STRONG_ENUMS 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define FEATURE_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 1
#    else
#      define FEATURE_COMPILER_CXX_TRAILING_RETURN_TYPES 0
#    endif

#    if __cpp_unicode_literals >= 200710 || (__INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__)) && (!defined(_MSC_VER) || __INTEL_COMPILER >= 1600))
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_UNICODE_LITERALS 0
#    endif

#    if __INTEL_COMPILER >= 1300 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 1
#    else
#      define FEATURE_COMPILER_CXX_UNIFORM_INITIALIZATION 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 1
#    else
#      define FEATURE_COMPILER_CXX_UNRESTRICTED_UNIONS 0
#    endif

#    if __cpp_user_defined_literals >= 200809 || (__INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__)) && (!defined(_MSC_VER) || __INTEL_COMPILER >= 1600))
#      define FEATURE_COMPILER_CXX_USER_LITERALS 1
#    else
#      define FEATURE_COMPILER_CXX_USER_LITERALS 0
#    endif

#    if __cpp_variable_templates >= 201304
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIABLE_TEMPLATES 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_MACROS 0
#    endif

#    if (__cpp_variadic_templates >= 200704 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 1
#    else
#      define FEATURE_COMPILER_CXX_VARIADIC_TEMPLATES 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 1
#    else
#      define FEATURE_COMPILER_CXX_TEMPLATE_TEMPLATE_PARAMETERS 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if defined(FEATURE_COMPILER_CXX_ALIGNAS) && FEATURE_COMPILER_CXX_ALIGNAS
#    define FEATURE_ALIGNAS(X) alignas(X)
#  elif FEATURE_COMPILER_IS_GNU || FEATURE_COMPILER_IS_Clang || FEATURE_COMPILER_IS_AppleClang
#    define FEATURE_ALIGNAS(X) __attribute__ ((__aligned__(X)))
#  elif FEATURE_COMPILER_IS_MSVC
#    define FEATURE_ALIGNAS(X) __declspec(align(X))
#  else
#    define FEATURE_ALIGNAS(X)
#  endif


#  if defined(FEATURE_COMPILER_CXX_ALIGNOF) && FEATURE_COMPILER_CXX_ALIGNOF
#    define FEATURE_ALIGNOF(X) alignof(X)
#  elif FEATURE_COMPILER_IS_GNU || FEATURE_COMPILER_IS_Clang || FEATURE_COMPILER_IS_AppleClang
#    define FEATURE_ALIGNOF(X) __alignof__(X)
#  elif FEATURE_COMPILER_IS_MSVC
#    define FEATURE_ALIGNOF(X) __alignof(X)
#  endif


#  ifndef FEATURE_DEPRECATED
#    if defined(FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED) && FEATURE_COMPILER_CXX_ATTRIBUTE_DEPRECATED
#      define FEATURE_DEPRECATED [[deprecated]]
#      define FEATURE_DEPRECATED_MSG(MSG) [[deprecated(MSG)]]
#    elif FEATURE_COMPILER_IS_GNU || FEATURE_COMPILER_IS_Clang
#      define FEATURE_DEPRECATED __attribute__((__deprecated__))
#      define FEATURE_DEPRECATED_MSG(MSG) __attribute__((__deprecated__(MSG)))
#    elif FEATURE_COMPILER_IS_MSVC
#      define FEATURE_DEPRECATED __declspec(deprecated)
#      define FEATURE_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#    else
#      define FEATURE_DEPRECATED
#      define FEATURE_DEPRECATED_MSG(MSG)
#    endif
#  endif


#  if defined(FEATURE_COMPILER_CXX_CONSTEXPR) && FEATURE_COMPILER_CXX_CONSTEXPR
#    define FEATURE_CONSTEXPR constexpr
#  else
#    define FEATURE_CONSTEXPR 
#  endif


#  if defined(FEATURE_COMPILER_CXX_DELETED_FUNCTIONS) && FEATURE_COMPILER_CXX_DELETED_FUNCTIONS
#    define FEATURE_DELETED_FUNCTION = delete
#  else
#    define FEATURE_DELETED_FUNCTION 
#  endif


#  if defined(FEATURE_COMPILER_CXX_EXTERN_TEMPLATES) && FEATURE_COMPILER_CXX_EXTERN_TEMPLATES
#    define FEATURE_EXTERN_TEMPLATE extern
#  else
#    define FEATURE_EXTERN_TEMPLATE 
#  endif


#  if defined(FEATURE_COMPILER_CXX_FINAL) && FEATURE_COMPILER_CXX_FINAL
#    define FEATURE_FINAL final
#  else
#    define FEATURE_FINAL 
#  endif


#  if defined(FEATURE_COMPILER_CXX_NOEXCEPT) && FEATURE_COMPILER_CXX_NOEXCEPT
#    define FEATURE_NOEXCEPT noexcept
#    define FEATURE_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define FEATURE_NOEXCEPT
#    define FEATURE_NOEXCEPT_EXPR(X)
#  endif


#  if defined(FEATURE_COMPILER_CXX_NULLPTR) && FEATURE_COMPILER_CXX_NULLPTR
#    define FEATURE_NULLPTR nullptr
#  elif FEATURE_COMPILER_IS_GNU
#    define FEATURE_NULLPTR __null
#  else
#    define FEATURE_NULLPTR 0
#  endif


#  if defined(FEATURE_COMPILER_CXX_OVERRIDE) && FEATURE_COMPILER_CXX_OVERRIDE
#    define FEATURE_OVERRIDE override
#  else
#    define FEATURE_OVERRIDE 
#  endif

#  if defined(FEATURE_COMPILER_CXX_STATIC_ASSERT) && FEATURE_COMPILER_CXX_STATIC_ASSERT
#    define FEATURE_STATIC_ASSERT(X) static_assert(X, #X)
#    define FEATURE_STATIC_ASSERT_MSG(X, MSG) static_assert(X, MSG)
#  else
#    define FEATURE_STATIC_ASSERT_JOIN(X, Y) FEATURE_STATIC_ASSERT_JOIN_IMPL(X, Y)
#    define FEATURE_STATIC_ASSERT_JOIN_IMPL(X, Y) X##Y
template<bool> struct FEATUREStaticAssert;
template<> struct FEATUREStaticAssert<true>{};
#    define FEATURE_STATIC_ASSERT(X) enum { FEATURE_STATIC_ASSERT_JOIN(FEATUREStaticAssertEnum, __LINE__) = sizeof(FEATUREStaticAssert<X>) }
#    define FEATURE_STATIC_ASSERT_MSG(X, MSG) enum { FEATURE_STATIC_ASSERT_JOIN(FEATUREStaticAssertEnum, __LINE__) = sizeof(FEATUREStaticAssert<X>) }
#  endif


#  if defined(FEATURE_COMPILER_CXX_THREAD_LOCAL) && FEATURE_COMPILER_CXX_THREAD_LOCAL
#    define FEATURE_THREAD_LOCAL thread_local
#  elif FEATURE_COMPILER_IS_GNU || FEATURE_COMPILER_IS_Clang || FEATURE_COMPILER_IS_AppleClang
#    define FEATURE_THREAD_LOCAL __thread
#  elif FEATURE_COMPILER_IS_MSVC
#    define FEATURE_THREAD_LOCAL __declspec(thread)
#  else
// FEATURE_THREAD_LOCAL not defined for this configuration.
#  endif

#endif

#endif
