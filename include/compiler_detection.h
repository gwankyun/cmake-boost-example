
// This is a generated file. Do not edit!

#ifndef CXX_COMPILER_DETECTION_H
#define CXX_COMPILER_DETECTION_H

#ifdef __cplusplus
# define CXX_COMPILER_IS_Comeau 0
# define CXX_COMPILER_IS_Intel 0
# define CXX_COMPILER_IS_PathScale 0
# define CXX_COMPILER_IS_Embarcadero 0
# define CXX_COMPILER_IS_Borland 0
# define CXX_COMPILER_IS_Watcom 0
# define CXX_COMPILER_IS_OpenWatcom 0
# define CXX_COMPILER_IS_SunPro 0
# define CXX_COMPILER_IS_HP 0
# define CXX_COMPILER_IS_Compaq 0
# define CXX_COMPILER_IS_zOS 0
# define CXX_COMPILER_IS_XLClang 0
# define CXX_COMPILER_IS_XL 0
# define CXX_COMPILER_IS_VisualAge 0
# define CXX_COMPILER_IS_PGI 0
# define CXX_COMPILER_IS_Cray 0
# define CXX_COMPILER_IS_TI 0
# define CXX_COMPILER_IS_Fujitsu 0
# define CXX_COMPILER_IS_GHS 0
# define CXX_COMPILER_IS_SCO 0
# define CXX_COMPILER_IS_ARMCC 0
# define CXX_COMPILER_IS_AppleClang 0
# define CXX_COMPILER_IS_ARMClang 0
# define CXX_COMPILER_IS_Clang 0
# define CXX_COMPILER_IS_GNU 0
# define CXX_COMPILER_IS_MSVC 0
# define CXX_COMPILER_IS_ADSP 0
# define CXX_COMPILER_IS_IAR 0
# define CXX_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef CXX_COMPILER_IS_Comeau
# define CXX_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef CXX_COMPILER_IS_Intel
# define CXX_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef CXX_COMPILER_IS_PathScale
# define CXX_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef CXX_COMPILER_IS_Embarcadero
# define CXX_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef CXX_COMPILER_IS_Borland
# define CXX_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef CXX_COMPILER_IS_Watcom
# define CXX_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef CXX_COMPILER_IS_OpenWatcom
# define CXX_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef CXX_COMPILER_IS_SunPro
# define CXX_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef CXX_COMPILER_IS_HP
# define CXX_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef CXX_COMPILER_IS_Compaq
# define CXX_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef CXX_COMPILER_IS_zOS
# define CXX_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef CXX_COMPILER_IS_XLClang
# define CXX_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef CXX_COMPILER_IS_XL
# define CXX_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef CXX_COMPILER_IS_VisualAge
# define CXX_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef CXX_COMPILER_IS_PGI
# define CXX_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef CXX_COMPILER_IS_Cray
# define CXX_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef CXX_COMPILER_IS_TI
# define CXX_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef CXX_COMPILER_IS_Fujitsu
# define CXX_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef CXX_COMPILER_IS_GHS
# define CXX_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef CXX_COMPILER_IS_SCO
# define CXX_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef CXX_COMPILER_IS_ARMCC
# define CXX_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef CXX_COMPILER_IS_AppleClang
# define CXX_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef CXX_COMPILER_IS_ARMClang
# define CXX_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef CXX_COMPILER_IS_Clang
# define CXX_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef CXX_COMPILER_IS_GNU
# define CXX_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef CXX_COMPILER_IS_MSVC
# define CXX_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef CXX_COMPILER_IS_ADSP
# define CXX_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef CXX_COMPILER_IS_IAR
# define CXX_COMPILER_IS_IAR 1


#endif

#  if CXX_COMPILER_IS_MSVC

#    if !(_MSC_VER >= 1600)
#      error Unsupported compiler version
#    endif

  /* _MSC_VER = VVRR */
# define CXX_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define CXX_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define CXX_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define CXX_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define CXX_COMPILER_VERSION_TWEAK (_MSC_BUILD)
# endif

#    if _MSC_VER >= 1600
#      define CXX_COMPILER_CXX_OVERRIDE 1
#    else
#      define CXX_COMPILER_CXX_OVERRIDE 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if defined(CXX_COMPILER_CXX_OVERRIDE) && CXX_COMPILER_CXX_OVERRIDE
#    define CXX_OVERRIDE override
#  else
#    define CXX_OVERRIDE 
#  endif

#endif

#endif
