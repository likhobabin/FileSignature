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
	${OBJECTDIR}/Source/fsBuffReadThead.o \
	${OBJECTDIR}/Source/fsFileAgent.o \
	${OBJECTDIR}/Source/fsIFileAgent.o \
	${OBJECTDIR}/Source/fsProgressBar.o \
	${OBJECTDIR}/Source/fsFileAgentThr.o \
	${OBJECTDIR}/Source/fsBitEncoder.o \
	${OBJECTDIR}/Source/fsMutex.o \
	${OBJECTDIR}/Source/fsBuffer.o \
	${OBJECTDIR}/Source/fsException.o \
	${OBJECTDIR}/Source/fsBuffWriteThread.o \
	${OBJECTDIR}/Source/fsIBuffThread.o


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

${OBJECTDIR}/Source/fsBuffReadThead.o: Source/fsBuffReadThead.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsBuffReadThead.o Source/fsBuffReadThead.cpp

${OBJECTDIR}/Source/fsFileAgent.o: Source/fsFileAgent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsFileAgent.o Source/fsFileAgent.cpp

${OBJECTDIR}/Source/fsIFileAgent.o: Source/fsIFileAgent.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsIFileAgent.o Source/fsIFileAgent.cpp

${OBJECTDIR}/Source/fsProgressBar.o: Source/fsProgressBar.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsProgressBar.o Source/fsProgressBar.cpp

${OBJECTDIR}/Source/fsFileAgentThr.o: Source/fsFileAgentThr.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsFileAgentThr.o Source/fsFileAgentThr.cpp

${OBJECTDIR}/Source/fsBitEncoder.o: Source/fsBitEncoder.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsBitEncoder.o Source/fsBitEncoder.cpp

${OBJECTDIR}/Source/fsMutex.o: Source/fsMutex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsMutex.o Source/fsMutex.cpp

${OBJECTDIR}/Source/fsBuffer.o: Source/fsBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsBuffer.o Source/fsBuffer.cpp

${OBJECTDIR}/Source/fsException.o: Source/fsException.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsException.o Source/fsException.cpp

${OBJECTDIR}/Source/fsBuffWriteThread.o: Source/fsBuffWriteThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsBuffWriteThread.o Source/fsBuffWriteThread.cpp

${OBJECTDIR}/Source/fsIBuffThread.o: Source/fsIBuffThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/Source
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -D_FILE_OFFSET_BITS=64 -D__USE_FILE_OFFSET64 -I. -IInclude -MMD -MP -MF $@.d -o ${OBJECTDIR}/Source/fsIBuffThread.o Source/fsIBuffThread.cpp

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
