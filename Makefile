CC=g++
FILES=DynamicStringArray.cc main.cc

dynamicstringarray:	
	${CC} -g ${FILES} -o project3
	./project3 		
clean: 
	rm -rf project3*	