.SUFFIXES:  .c .cpp .o .obj .a .lib

CPP=g++ -fpic
LINK=g++
PREP=g++ -E -P
PUMP=pump
COPY=cp
DEL=rm
MAKE=make
ECHO=echo
LIBLINK=ar

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDEDIR) -c $< -o $@ 2>> output



ISLIB=N
DEFINES=-DLINUX -DGCC
target=parse

DEBUG_DEFINE=-DDEBUG -DDEBUG_LOG

APPEND_CPPFLAGS=-g -O0 -pthread

PROFILE_CPPFLAGS=

WARNING_CPPFLAGS=-Wall -Wno-sign-compare

CPPFLAGS=     $(APPEND_CPPFLAGS) $(PROFILE_CPPFLAGS) $(WARNING_CPPFLAGS) $(DEBUG_DEFINE) $(DEFINES)

LIBS= -lpthread -lrt -ldl    

DEBUG_LDFLAGS=-g

MAP_LDFLAGS=

PROFILE_LDFLAGS=

WARNING_LDFLAGS=-Wall -Wno-sign-compare

LDFLAGS=     $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS) $(WARNING_LDFLAGS)

LIBARFLAGS=    -static $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)

DLLARFLAGS=    -shared $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)


all: makefile code

code: clearoutput $(target)

makefile: ./package.des  iniFile_parse.prj
	amake iniFile_parse.prj
	@$(ECHO) rerun nmake
	@exit 1

clearoutput:
	@$(ECHO) Compiling... > output

iniFile_parse_obj= ./config.o  ./iniFile_parse.o 
iniFile_parse_include= ./config.h 
iniFile_parse_includedir=-I./.

all_objs= $(iniFile_parse_obj) 
all_libs= $(iniFile_parse_lib) 
INCLUDEDIR= $(iniFile_parse_includedir) 

./config.o: ./config.cpp $(iniFile_parse_include)  

./iniFile_parse.o: ./iniFile_parse.cpp $(iniFile_parse_include)  



$(target): $(all_objs)
	$(LINK) $(LDFLAGS) -o $@ $(all_objs) $(all_libs) $(LIBS) >> output


clean:
	-$(DEL) $(iniFile_parse_obj)
	-$(DEL) $(target)

pump:  

