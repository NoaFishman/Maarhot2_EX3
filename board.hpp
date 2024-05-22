/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include "vertex.hpp"
#include "hex.hpp"
#include "road.hpp"
using namespace std;

namespace noa{

    class Board{

        vector<Vertex> ver;
        vector<Hex> hexa;
        vector<Road> roads;

        public:

            void biuldBoard();
            Vertex& getVer(vector<string> places, vector<int> placesNum);
            Board getBoard(){
                return *this;
            }

            // constractor
            Board(){

                Vertex v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
                Vertex v11, v12, v13, v14, v15, v16, v17, v18, v19, v20;
                Vertex v21, v22, v23, v24, v25, v26, v27, v28, v29, v30;
                Vertex v31, v32, v33, v34, v35, v36, v37, v38, v39, v40;
                Vertex v41, v42, v43, v44, v45, v46, v47, v48, v49, v50;
                Vertex v51, v52, v53, v54;

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

                Hex h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15, h16, h17, h18, h19;

                hexa.push_back(h1), hexa.push_back(h2), hexa.push_back(h3), hexa.push_back(h4), hexa.push_back(h5);
                hexa.push_back(h6), hexa.push_back(h7), hexa.push_back(h8), hexa.push_back(h9), hexa.push_back(h10);
                hexa.push_back(h11), hexa.push_back(h12), hexa.push_back(h13), hexa.push_back(h14), hexa.push_back(h15);
                hexa.push_back(h16), hexa.push_back(h17), hexa.push_back(h18), hexa.push_back(h19);

                h1.buildHex(v1,v2,v3,v4,v5,v6), h2.buildHex(v3,v5,v7,v8,v9,v10);
                h3.buildHex(v4,v6,v11,v12,v13,v14), h4.buildHex(v8,v9,v15,v16,v17,v18);
                h5.buildHex(v5,v6,v7,v14,v19,v20), h6.buildHex(v12,v13,v21,v22,v23,v24);
                h7.buildHex(v7,v8,v18,v19,v25,v26), h8.buildHex(v13,v14,v20,v24,v27,v28);
                h9.buildHex(v17,v18,v25,v29,v30,v31), h10.buildHex(v19,v20,v26,v27,v32,v33);
                h11.buildHex(v23,v24,v28,v34,v36,v35), h12.buildHex(v25,v26,v31,v32,v37,v38);
                h13.buildHex(v27,v28,v33,v35,v39,v40), h14.buildHex(v30,v31,v37,v41,v42,v43);
                h15.buildHex(v32,v33,v38,v39,v44,v45), h16.buildHex(v35,v36,v40,v46,v47,v48);
                h17.buildHex(v37,v38,v43,v44,v49,v50), h18.buildHex(v39,v40,v45,v46,v51,v52);
                h19.buildHex(v44,v45,v50,v51,v53,v54);

                v1.buildVer1(h1);
                v2.buildVer1(h1);
                v3.buildVer2(h1,h2);
                v4.buildVer2(h1,h3);
                v5.buildVer3(h1,h2,h5);
                v6.buildVer3(h1,h3,h5);
                v7.buildVer3(h2,h5,h7);
                v8.buildVer3(h2,h4,h7);
                v9.buildVer2(h2,h4);
                v10.buildVer1(h2);
                v11.buildVer1(h3);
                v12.buildVer2(h3,h6);
                v13.buildVer3(h3,h6,h8);
                v14.buildVer3(h3,h5,h8);
                v15.buildVer1(h4);
                v16.buildVer1(h4);
                v17.buildVer2(h4,h9);
                v18.buildVer3(h4,h7,h9);
                v19.buildVer3(h5,h7,h10);
                v20.buildVer3(h5,h8,h10);
                v21.buildVer1(h6);
                v22.buildVer1(h6);
                v23.buildVer2(h6,h11);
                v24.buildVer3(h6,h8,h11);
                v25.buildVer3(h7,h9,h12);
                v26.buildVer3(h7,h10,h12);
                v27.buildVer3(h8,h10,h13);
                v28.buildVer3(h8,h11,h13);
                v29.buildVer1(h9);
                v30.buildVer2(h9,h14);
                v31.buildVer3(h9,h12,h14);
                v32.buildVer3(h10,h12,h15);
                v33.buildVer3(h10,h13,h15);
                v34.buildVer1(h11);
                v35.buildVer3(h11,h13,h16);
                v36.buildVer2(h11,h16);
                v37.buildVer3(h12,h14,h17);
                v38.buildVer3(h12,h15,h17);
                v39.buildVer3(h13,h15,h18);
                v40.buildVer3(h13,h16,h18);
                v41.buildVer1(h14);
                v42.buildVer1(h14);
                v43.buildVer2(h14,h17);
                v44.buildVer3(h15,h17,h19);
                v45.buildVer3(h15,h18,h19);
                v46.buildVer2(h16,h18);
                v47.buildVer1(h16);
                v48.buildVer1(h16);
                v49.buildVer1(h17);
                v50.buildVer2(h17,h19);
                v51.buildVer2(h18,h19);
                v52.buildVer1(h18);
                v53.buildVer1(h19);
                v54.buildVer1(h19);

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
                            
                
            }
};
    
}