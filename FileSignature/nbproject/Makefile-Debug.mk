#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Source/fsDataFormer.o \
	${OBJECTDIR}/Source/fsUnifException.o \
	${OBJECTDIR}/Source/fsBitGenerator.o


# C Compiler Flags
CFLAGS=-m32

# CC Compiler Flags
CCFLAGS=-m32
CXXFLAGS=-m32

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfilesignature.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfilesignature.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfilesignature.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfilesignature.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfilesignature.a

${OBJECTDIR}/Source/fsDataFormer.o: Source/fsDataFormer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsDataFormer.o Source/fsDataFormer.cpp

${OBJECTDIR}/Source/fsUnifException.o: Source/fsUnifException.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsUnifException.o Source/fsUnifException.cpp

${OBJECTDIR}/Source/fsBitGenerator.o: Source/fsBitGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsBitGenerator.o Source/fsBitGenerator.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfilesignature.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
