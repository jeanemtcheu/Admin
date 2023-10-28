CXX = g++
CXXFLAGS = -Wall

proj2:  Student.o Admin.o Course.o proj2.cpp
        $(CXX) $(CXXFLAGS) Student.o Course.o Admin.o proj2.cpp -o proj2

Admin.o: Student.o Course.o Admin.cpp Admin.h
        $(CXX) $(CXXFLAGS) -c Admin.cpp

Student.o: Student.h Student.cpp Course.o
        $(CXX) $(CXXFLAGS) -c Student.cpp

Course.o: Course.h Course.cpp
        $(CXX) $(CXXFLAGS) -c Course.cpp

clean:
        rm *.o*
        rm *~

run:
        ./proj2

submit:
        cp Course.cpp Course.h Student.cpp Student.h Admin.h Admin.cpp proj2.cpp ~/cs202proj/proj2

