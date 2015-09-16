g++ -g -o a.out test.cpp dataset.pb.cpp -I. -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf -pthread -L/usr/lib/x86_64-linux-gnu -lleveldb
