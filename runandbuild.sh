./build.sh
cd build
./pathtracer -s 20 -o test.png -i "../obj/dragon2.obj" -c "../obj/dragon2.cfg"
display test.png 