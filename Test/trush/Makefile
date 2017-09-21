DESTINATION := test  
LIBS :=   
INCLUDES := .  


RM := rm -f  
PS=cpp  
SOURCE := $(wildcard *.$(PS))  
OBJS := $(patsubst %.$(PS),%.o,$(SOURCE))  
DEPS := $(patsubst %.o,%.d,$(OBJS))  
MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))  
MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.$(PS),$(MISSING_DEPS)))  

.PHONY : all deps objs clean rebuild  

all : $(DESTINATION)  

deps : $(DEPS)  
	$(CC) -MM -MMD $(SOURCE)  


objs : $(OBJS)  

clean :  
	@$(RM) *.o  
	@$(RM) *.d  
	@$(RM) $(DESTINATION)  

