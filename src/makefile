IDIR = ../include

CC = g++
CXXFLAGS = -W -Wall -I$(IDIR)
GCOVFLAGS = -ftest-coverage -fprofile-arcs

EDIR = ../exec
ODIR = ../obj

T_EDIR = ../t_exec
T_SDIR = ../t_src

_T_SRC = $(patsubst $(T_SDIR)/%,%,$(wildcard $(T_SDIR)/*.cc))

LIBS = -lm
DEBUG = -g

_DEPS = $(patsubst $(IDIR)/%,%,$(DEPS))
DEPS = $(wildcard $(IDIR)/*.h)

_OBJ = $(patsubst %.cc,%.o,$(wildcard *.cc))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_T_OBJ = $(patsubst %.h,%.o,$(_DEPS)) $(patsubst %.cc,%.o,$(_T_SRC))
T_OBJ = $(patsubst %,$(ODIR)/%,$(_T_OBJ))

T_SRC = $(patsubst %,$(T_SDIR)/%,$(wildcard *.cc))

$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS) $(DEBUG)

$(ODIR)/%.o: $(T_SDIR)/%.cc $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS) $(GCOVFLAGS) $(DEBUG)

main: $(OBJ)
	$(CC) -o $(EDIR)/$@ $^ $(CXXFLAGS) $(LIBS) $(DEBUG)

test: $(T_OBJ)
	$(CC) -o $(T_EDIR)/$@ $^ $(CXXFLAGS) $(LIBS) $(GCOVFLAGS) $(DEBUG)

.PHONY: clean

clean:
	rm -f $(wildcard $(ODIR)/*.o)
