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
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/6e7042a3/Keyword.o \
	${OBJECTDIR}/_ext/6e7042a3/KeywordFactory.o \
	${OBJECTDIR}/_ext/6e7042a3/Operator.o \
	${OBJECTDIR}/_ext/6e7042a3/OperatorFactory.o \
	${OBJECTDIR}/_ext/6e7042a3/Parenthesis.o \
	${OBJECTDIR}/_ext/6e7042a3/ParenthesisFactory.o \
	${OBJECTDIR}/_ext/6e7042a3/StringSet.o \
	${OBJECTDIR}/_ext/6e7042a3/Subset.o \
	${OBJECTDIR}/_ext/6e7042a3/Token.o \
	${OBJECTDIR}/_ext/6e7042a3/TokenFactory.o \
	${OBJECTDIR}/_ext/6e7042a3/Tokenizer.o \
	${OBJECTDIR}/_ext/6e7042a3/TokenizerLib.o \
	${OBJECTDIR}/ANode.o \
	${OBJECTDIR}/B2ndHalfNode.o \
	${OBJECTDIR}/BNode.o \
	${OBJECTDIR}/FNode.o \
	${OBJECTDIR}/INode.o \
	${OBJECTDIR}/MNode.o \
	${OBJECTDIR}/P2Node.o \
	${OBJECTDIR}/PNode.o \
	${OBJECTDIR}/SNode.o \
	${OBJECTDIR}/Tree.o \
	${OBJECTDIR}/TreeNode.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parserccrico

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parserccrico: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parserccrico ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/6e7042a3/Keyword.o: ../../Rico/Keyword.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/Keyword.o ../../Rico/Keyword.cpp

${OBJECTDIR}/_ext/6e7042a3/KeywordFactory.o: ../../Rico/KeywordFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/KeywordFactory.o ../../Rico/KeywordFactory.cpp

${OBJECTDIR}/_ext/6e7042a3/Operator.o: ../../Rico/Operator.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/Operator.o ../../Rico/Operator.cpp

${OBJECTDIR}/_ext/6e7042a3/OperatorFactory.o: ../../Rico/OperatorFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/OperatorFactory.o ../../Rico/OperatorFactory.cpp

${OBJECTDIR}/_ext/6e7042a3/Parenthesis.o: ../../Rico/Parenthesis.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/Parenthesis.o ../../Rico/Parenthesis.cpp

${OBJECTDIR}/_ext/6e7042a3/ParenthesisFactory.o: ../../Rico/ParenthesisFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/ParenthesisFactory.o ../../Rico/ParenthesisFactory.cpp

${OBJECTDIR}/_ext/6e7042a3/StringSet.o: ../../Rico/StringSet.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/StringSet.o ../../Rico/StringSet.cpp

${OBJECTDIR}/_ext/6e7042a3/Subset.o: ../../Rico/Subset.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/Subset.o ../../Rico/Subset.cpp

${OBJECTDIR}/_ext/6e7042a3/Token.o: ../../Rico/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/Token.o ../../Rico/Token.cpp

${OBJECTDIR}/_ext/6e7042a3/TokenFactory.o: ../../Rico/TokenFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/TokenFactory.o ../../Rico/TokenFactory.cpp

${OBJECTDIR}/_ext/6e7042a3/Tokenizer.o: ../../Rico/Tokenizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/Tokenizer.o ../../Rico/Tokenizer.cpp

${OBJECTDIR}/_ext/6e7042a3/TokenizerLib.o: ../../Rico/TokenizerLib.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/6e7042a3
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6e7042a3/TokenizerLib.o ../../Rico/TokenizerLib.cpp

${OBJECTDIR}/ANode.o: ANode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ANode.o ANode.cpp

${OBJECTDIR}/B2ndHalfNode.o: B2ndHalfNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/B2ndHalfNode.o B2ndHalfNode.cpp

${OBJECTDIR}/BNode.o: BNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BNode.o BNode.cpp

${OBJECTDIR}/FNode.o: FNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FNode.o FNode.cpp

${OBJECTDIR}/INode.o: INode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/INode.o INode.cpp

${OBJECTDIR}/MNode.o: MNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MNode.o MNode.cpp

${OBJECTDIR}/P2Node.o: P2Node.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/P2Node.o P2Node.cpp

${OBJECTDIR}/PNode.o: PNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PNode.o PNode.cpp

${OBJECTDIR}/SNode.o: SNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SNode.o SNode.cpp

${OBJECTDIR}/Tree.o: Tree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tree.o Tree.cpp

${OBJECTDIR}/TreeNode.o: TreeNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TreeNode.o TreeNode.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/parserccrico

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
