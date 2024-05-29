/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
//#include "vertex.hpp"
#include "hex.hpp"
//#include "road.hpp"
using namespace std;

namespace noa{

    class Board{

        vector<Vertex> ver;
        vector<Hex> hexa;
        vector<Road> roads;

        public:

            void biuldBoard();
            void printBoard();
            Vertex& getVer(int verNum);
            bool newRoad(Vertex& v1, Vertex& v2, int n);
            Board getBoard(){
                return *this;
            }
            void getCardsStart();
            void getCards(int d);
            bool canBuildRoad(Vertex& v1, Vertex& v2, int n);

            // constractor
            Board(){

                // Vertex v1(1), v2(2), v3(3), v4(4), v5(5), v6(6), v7(7), v8(8), v9(9), v10(10);
                // Vertex v11(11), v12(12), v13(13), v14(14), v15(15), v16(16), v17(17), v18(18), v19(19), v20(20);
                // Vertex v21(21), v22(22), v23(23), v24(24), v25(25), v26(26), v27(27), v28(28), v29(29), v30(30);
                // Vertex v31(31), v32(32), v33(33), v34(34), v35(35), v36(36), v37(37), v38(38), v39(39), v40(40);
                // Vertex v41(41), v42(42), v43(43), v44(44), v45(45), v46(46), v47(47), v48(48), v49(49), v50(50);
                // Vertex v51(51), v52(52), v53(53), v54(54);

                Vertex v1(1,1,2), v2(2,1,3), v3(3,2,4,7), v4(4,3,5,8), v5(5,7,11,15);
                Vertex v6(6,8,11,16), v7(7,15,19,23), v8(8,14,19,22), v9(9,6,10,14), v10(10,4,6);
                Vertex v11(11,5,9), v12(12,9,12,17), v13(13,17,20,25), v14(14,16,20,24), v15(15,10,13); 
                Vertex v16(16,13,21), v17(17,21,27,30), v18(18,22,27,31), v19(19,23,28,35), v20(20,28,24,33);
                Vertex v21(21,12,18), v22(22,18,26), v23(23,26,29,35), v24(24,25,29,34), v25(25,31,36,39);
                Vertex v26(26,32,36,40), v27(27,33,37,41), v28(28,34,37,42), v29(29,30,38), v30(30,38,44,47);
                Vertex v31(31,39,44,48), v32(32,40,45,49), v33(33,41,45,50), v34(34,35,43), v35(35,42,46,51);
                Vertex v36(36,43,46,52), v37(37,48,53,56), v38(38,49,53,57), v39(39,50,54,58), v40(40,51,54,59);
                Vertex v41(41,47,55), v42(42,55,61), v43(43,56,61,64), v44(44,57,62,65), v45(45,58,62,66);
                Vertex v46(46,59,63,67), v47(47,60,63), v48(48,52,60), v49(49,64,68), v50(50,65,68,70);
                Vertex v51(51,66,69,71), v52(52,67,69), v53(53,70,72), v54(54,71,72);

                Hex h1(1,2,3,4,5,6), h2(3,5,7,8,9,10);
                Hex h3(4,6,11,12,13,14), h4(8,9,15,16,17,18);
                Hex h5(5,6,7,14,19,20), h6(12,13,21,22,23,24);
                Hex h7(7,8,18,19,25,26), h8(13,14,20,24,27,28);
                Hex h9(17,18,25,29,30,31), h10(19,20,26,27,32,33);
                Hex h11(23,24,28,34,36,35), h12(25,26,31,32,37,38);
                Hex h13(27,28,33,35,39,40), h14(30,31,37,41,42,43);
                Hex h15(32,33,38,39,44,45), h16(35,36,40,46,47,48);
                Hex h17(37,38,43,44,49,50), h18(39,40,45,46,51,52);
                Hex h19(44,45,50,51,53,54);

                hexa.push_back(h1), hexa.push_back(h2), hexa.push_back(h3), hexa.push_back(h4), hexa.push_back(h5);
                hexa.push_back(h6), hexa.push_back(h7), hexa.push_back(h8), hexa.push_back(h9), hexa.push_back(h10);
                hexa.push_back(h11), hexa.push_back(h12), hexa.push_back(h13), hexa.push_back(h14), hexa.push_back(h15);
                hexa.push_back(h16), hexa.push_back(h17), hexa.push_back(h18), hexa.push_back(h19);

                Road r1 {v1, v2}; roads.push_back(r1);
                Road r2 {v1, v3}; roads.push_back(r2);
                Road r3 {v2,v4}; roads.push_back(r3);
                Road r4 {v3,v10}; roads.push_back(r4);
                Road r5 {v4,v11}; roads.push_back(r5);
                Road r6 {v9,v10}; roads.push_back(r6);
                Road r7 {v3,v5}; roads.push_back(r7);
                Road r8 {v4,v6}; roads.push_back(r8);
                Road r9 {v11,v12}; roads.push_back(r9);
                Road r10 {v9,v15}; roads.push_back(r10);
                Road r11 {v5,v6}; roads.push_back(r11);
                Road r12 {v12,v21}; roads.push_back(r12);
                Road r13 {v15,v16}; roads.push_back(r13);
                Road r14 {v9,v8}; roads.push_back(r14);
                Road r15 {v7,v5}; roads.push_back(r15);
                Road r16 {v6,v14}; roads.push_back(r16);
                Road r17 {v12,v13}; roads.push_back(r17);
                Road r18 {v21,v22}; roads.push_back(r18);
                Road r19 {v7,v8}; roads.push_back(r19);
                Road r20 {v13,v14}; roads.push_back(r20);
                Road r21 {v16,v17}; roads.push_back(r21);
                Road r22 {v8,v18}; roads.push_back(r22);
                Road r23 {v7,v19}; roads.push_back(r23);
                Road r24 {v14,v20}; roads.push_back(r24);
                Road r25 {v13,v24}; roads.push_back(r25);
                Road r26 {v22,v23}; roads.push_back(r26);
                Road r27 {v17,v18}; roads.push_back(r27);
                Road r28 {v19,v20}; roads.push_back(r28);
                Road r29 {v23,v24}; roads.push_back(r29);
                Road r30 {v17,v29}; roads.push_back(r30);
                Road r31 {v18,v25}; roads.push_back(r31);
                Road r32 {v19,v26}; roads.push_back(r32);
                Road r33 {v20,v27}; roads.push_back(r33);
                Road r34 {v28,v24}; roads.push_back(r34);
                Road r35 {v23,v34}; roads.push_back(r35);
                Road r36 {v25,v26}; roads.push_back(r36);
                Road r37 {v27,v28}; roads.push_back(r37);
                Road r38 {v29,v30}; roads.push_back(r38);
                Road r39 {v31,v25}; roads.push_back(r39);
                Road r40 {v26,v32}; roads.push_back(r40);
                Road r41 {v27,v33}; roads.push_back(r41);
                Road r42 {v28,v35}; roads.push_back(r42);
                Road r43 {v34,v36}; roads.push_back(r43);
                Road r44 {v30,v31}; roads.push_back(r44);
                Road r45 {v32,v33}; roads.push_back(r45);
                Road r46 {v35,v36}; roads.push_back(r46);
                Road r47 {v30,v41}; roads.push_back(r47);
                Road r48 {v31,v37}; roads.push_back(r48);
                Road r49 {v38,v32}; roads.push_back(r49);
                Road r50 {v33,v39}; roads.push_back(r50);
                Road r51 {v35,v40}; roads.push_back(r51);
                Road r52 {v36,v48}; roads.push_back(r52);
                Road r53 {v37,v38}; roads.push_back(r53);
                Road r54 {v39,v40}; roads.push_back(r54);
                Road r55 {v41,v42}; roads.push_back(r55);
                Road r56 {v43,v37}; roads.push_back(r56);
                Road r57 {v38,v44}; roads.push_back(r57);
                Road r58 {v45,v39}; roads.push_back(r58);
                Road r59 {v40,v46}; roads.push_back(r59);
                Road r60 {v47,v48}; roads.push_back(r60);
                Road r61 {v42,v43}; roads.push_back(r61);
                Road r62 {v44,v45}; roads.push_back(r62);
                Road r63 {v46,v47}; roads.push_back(r63);
                Road r64 {v43,v49}; roads.push_back(r64);
                Road r65 {v50,v44}; roads.push_back(r65);
                Road r66 {v45,v51}; roads.push_back(r66);
                Road r67 {v46,v52}; roads.push_back(r67);
                Road r68 {v49,v50}; roads.push_back(r68);
                Road r69 {v51,v52}; roads.push_back(r69);
                Road r70 {v50,v53}; roads.push_back(r70);
                Road r71 {v51,v54}; roads.push_back(r71);
                Road r72 {v53,v54}; roads.push_back(r72);

                ver.push_back(v1), ver.push_back(v2), ver.push_back(v3), ver.push_back(v4), ver.push_back(v5);
                ver.push_back(v6), ver.push_back(v7), ver.push_back(v8), ver.push_back(v9), ver.push_back(v10);
                ver.push_back(v11), ver.push_back(v12), ver.push_back(v13), ver.push_back(v14), ver.push_back(v15);
                ver.push_back(v16), ver.push_back(v17), ver.push_back(v18), ver.push_back(v19), ver.push_back(v20);
                ver.push_back(v21), ver.push_back(v22), ver.push_back(v23), ver.push_back(v24), ver.push_back(v25);
                ver.push_back(v26), ver.push_back(v27), ver.push_back(v28), ver.push_back(v29), ver.push_back(v30);
                ver.push_back(v31), ver.push_back(v32), ver.push_back(v33), ver.push_back(v34), ver.push_back(v35);
                ver.push_back(v36), ver.push_back(v37), ver.push_back(v38), ver.push_back(v39), ver.push_back(v40);
                ver.push_back(v41), ver.push_back(v42), ver.push_back(v43), ver.push_back(v44), ver.push_back(v45);
                ver.push_back(v46), ver.push_back(v47), ver.push_back(v48), ver.push_back(v49), ver.push_back(v50);
                ver.push_back(v51), ver.push_back(v52), ver.push_back(v53), ver.push_back(v54);
                            
            }

            ~Board(){}

    };

    
}