
output: Market.o utils.o user.o admin.o client.o product.o item.o purchase.o bill.o system.o 
	g++ Market.o utils.o user.o admin.o client.o product.o item.o purchase.o bill.o system.o -o output

Market.o: Market.cpp
	g++ -c Market.cpp

utils.o: utils.cpp utils.h
	g++ -c utils.cpp

user.o: user.cpp user.h
	g++ -c user.cpp

admin.o: admin.cpp admin.h
	g++ -c admin.cpp

client.o: client.cpp client.h
	g++ -c client.cpp

product.o: product.cpp product.h
	g++ -c product.cpp

item.o: item.cpp item.h
	g++ -c item.cpp

purchase.o: purchase.cpp purchase.h
	g++ -c purchase.cpp

bill.o: bill.cpp bill.h
	g++ -c bill.cpp

system.o: system.cpp system.h
	g++ -c system.cpp

clean:
	rm *.o output