/*
ID: 319055430
Email: noa.fishman@gmail.com
*/

#include "board.hpp"
using namespace std;

namespace noa{

    //RandomInitializer randomInitializer;

    void Board:: biuldBoard(){
        vector<int> numbers = {0,0,1,2,2,2,2,0,2,2,2,2,1}; // th index is the number we need to place
        vector<int> resource = {3,3,4,4,4}; // 0 = Mountains, 1 = Hills, 2 = Fields, 3 = Forest, 4 = Pasture
        vector<string> places; 
        places.push_back("🪨");
        places.push_back("🧱");
        places.push_back("🌾");
        places.push_back("🪵");
        places.push_back("🐑");
        int x1 = 1;
        int x2 =1;

        for(int i=0; i< 19; ++i){
            if(i == 9){
                hexa[i].setHex("0", 5); // represent the desert in the middle
            }
            else{
                x1 = rand()%13;
                x2 = rand()%5;
                while(numbers[x1] == 0){
                    x1 = (x1 + 1) %13;
                }
                while(resource[x2] == 0){
                    x2 = (x2 + 1) %5;
                }
                hexa[i].setHex(places[x2], x1);
                numbers[x1]--;
                resource[x2]--;
            }
        }
    }

    void Board:: biuldBoardDemo(){
        hexa[0].setHex("🪨", 10);
        hexa[1].setHex("🌾", 12);
        hexa[2].setHex("🐑", 2);
        hexa[3].setHex("🌾", 9);
        hexa[4].setHex("🧱", 6);
        hexa[5].setHex("🪵", 9);
        hexa[6].setHex("🪵", 11);
        hexa[7].setHex("🐑", 4);
        hexa[8].setHex("🪵", 8);
        hexa[9].setHex("0", 0);
        hexa[10].setHex("🧱", 10);
        hexa[11].setHex("🪨", 3);
        hexa[12].setHex("🪵", 3);
        hexa[13].setHex("🧱", 5);
        hexa[14].setHex("🌾", 4);
        hexa[15].setHex("🪨", 8);
        hexa[16].setHex("🌾", 6);
        hexa[17].setHex("🐑", 5);
        hexa[18].setHex("🐑", 11);
    }

    // return the vertex the player chose
    Vertex& Board::getVer(int verNum){
        return ver[verNum-1];
    }

    // find the road and build there
    bool Board::newRoad(Vertex& v1, Vertex& v2, int n){

        int curr = static_cast<int>(roads.size());

        for(int i=0; i<static_cast<int>(roads.size()); i++){
            if(roads[i].isThisRoad(v1,v2) == true){
                curr = i;
                break;
            }
        }

        if(curr < static_cast<int>(roads.size()) && roads[curr].isTaken() == false){
            
            roads[curr].setRoad(n);
            return true;
        }
        else{
            cout << "cant build here" ;
            if(curr < static_cast<int>(roads.size())){
                cout << " already taken  " << endl;
            }
            else{
                cout << " this is not road " << endl;
            }
            return false;
        }
        return true;
    }

    // check that the player can build ther a road
    bool Board::canBuildRoad(Vertex& v1, Vertex& v2, int n){ 

        int numV1 = v1.getNum(), numV2 = v2.getNum();

        if(ver[numV1 -1].getOwner() == n && ver[numV1 -1].getBuild() != 0){
            return true; // he have city or settelment in v1  
        }

        if(ver[numV2 -1].getOwner() == n && ver[numV2 -1].getBuild() != 0){
            return true; // he have city or settelment in v2
        }

        vector<int> ro = ver[numV1 -1].gerRoads(); // get the vertex's roads numbers
        if(!ro.empty()){
            for(int i=0; i<static_cast<int>(ro.size()); i++){
                if(roads[ro[i]-1].getOwner() == n){ //check if own of the roads around this vertex belong to the player
                    return true;
                }
            }
        }

        vector<int> ro2 = ver[numV2 -1].gerRoads(); // get the vertex's roads numbers
        if(!ro2.empty()){
            for(int i=0; i<static_cast<int>(ro2.size()); i++){ 
                if(roads[ro2[i]-1].getOwner() == n){ //check if own of the roads around this vertex belong to the player
                    return true;
                }
            }
        }

        return false;

    }

    void Board::printVer(){
        for(int i=0; i<static_cast<int>(ver.size()); ++i){
            cout << "ver num: " << ver[i].getNum() <<" ver build: "<<ver[i].getBuild() << " ver owner: "<<ver[i].getOwner()<<endl;
        }
    }

    bool Board::canBuildSettel(int v, int n, Player* pNew){
        vector<int> ro = ver[v -1].gerRoads();
        if(!ro.empty()){
            for(int i=0; i<static_cast<int>(ro.size()); i++){
                //check if own of the roads around this vertex belong to the player
                int nextV = roads[ro[i]-1].getTheOtherVer(v);
                if(ver[nextV -1].getBuild() != 0){
                    //cout << "sorry you dond have road here" << endl;
                    return false;
                }
            }
        }
        if(!ro.empty()){
            for(int i=0; i<static_cast<int>(ro.size()); i++){
                if(roads[ro[i]-1].getOwner() == n){ //check if own of the roads around this vertex belong to the player
                    int nextV = roads[ro[i]-1].getTheOtherVer(v);
                    vector<int> ro2 = ver[nextV -1].gerRoads();
                    if(!ro2.empty()){
                        for(int j=0; j<static_cast<int>(ro2.size()); j++){
                            if( roads[ro2[j]-1].getOwner() == n && ver[v - 1].newSettel(n, 1, pNew) ){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        cout << "sorry you can't settel here" << endl;
        return false;
    }

    bool Board::canBuildSettelFirst(int v, int n, Player* pNew){
        bool flag = true;
        vector<int> ro = ver[v -1].gerRoads();
        if(!ro.empty()){
            for(int i=0; i<static_cast<int>(ro.size()); i++){
                int nextV = roads[ro[i]-1].getTheOtherVer(v);
                if(ver[nextV -1].getBuild() != 0){
                    flag = false;
                }
            }
        }
        if(ver[v - 1].newSettel(n, 1, pNew) && flag){
            return true;
        }
        return false;
    }

    void Board::getCardsStart(){
        for(int i=0; i< static_cast<int>(hexa.size()); i++){
            vector<int> temp = hexa[i].getCards();
            ver[temp[0] -1].getCards(hexa[i].getPlace());
            ver[temp[1] -1].getCards(hexa[i].getPlace());
            ver[temp[2] -1].getCards(hexa[i].getPlace());
            ver[temp[3] -1].getCards(hexa[i].getPlace());
            ver[temp[4] -1].getCards(hexa[i].getPlace());
            ver[temp[5] -1].getCards(hexa[i].getPlace());
        }
    }
    void Board::getCards(int d){
        for(int i=0; i< static_cast<int>(hexa.size()); i++){
            int num = hexa[i].getNum();
            vector<int> temp = hexa[i].getCards();
            if(num == d){
                ver[temp[0] -1].getCards(hexa[i].getPlace());
                ver[temp[1] -1].getCards(hexa[i].getPlace());
                ver[temp[2] -1].getCards(hexa[i].getPlace());
                ver[temp[3] -1].getCards(hexa[i].getPlace());
                ver[temp[4] -1].getCards(hexa[i].getPlace());
                ver[temp[5] -1].getCards(hexa[i].getPlace());
            }
        }
    }

    //   void Board::printBoard(){

    //     cout << "                            (1)---(2)"<< endl;
    //     cout << "                           /         \\ "<< endl;
    //     cout << "                          /     " << hexa[0].getPlace()<<"     \\ "<< endl;
    //     cout << "                (10)---(3)     "<< internal << setw(2)<<hexa[0].getNum()<<"      (4)---(11) "<< endl;
    //     cout << "               /          \\           /          \\ "<< endl;
    //     cout << "              /     "<<hexa[1].getPlace() <<"     \\         /     "<<hexa[2].getPlace()<<"     \\ "<< endl;
    //     cout << "    (15)---(9)      "<< internal << setw(2)<<hexa[1].getNum()<<"      (5)---(6)     "<< internal << setw(2)<<hexa[2].getNum()<<"      (12)---(21)"<< endl;
    //     cout << "  /           \\           /         \\            /           \\ "<< endl;
    //     cout << " /      "<<hexa[3].getPlace()<<"     \\         /    "<<hexa[4].getPlace()<<"      \\          /     "<<hexa[5].getPlace()<<"      \\ "<< endl;
    //     cout << "(16)   "<< internal << setw(2)<<hexa[3].getNum()<<"      (8)---(7)      "<< internal << setw(2)<<hexa[4].getNum()<<"      (14)---(13)      "<< internal << setw(2)<<hexa[5].getNum()<<"     (22)"<< endl;
    //     cout << " \\            /         \\             /         \\             / "<< endl;
    //     cout << "  \\          /    "<<hexa[6].getPlace()<<"      \\          /      "<<hexa[7].getPlace()<<"    \\           / "<< endl;
    //     cout << "   (17)---(18)      "<< internal << setw(2)<<hexa[6].getNum()<<"     (19)---(20)     "<< internal << setw(2)<<hexa[7].getNum()<<"     (24)---(23)"<< endl;
    //     cout << "  /          \\            /          \\           /           \\ "<< endl;
    //     cout << " /     "<<hexa[8].getPlace()<<"     \\          /   Desert   \\          /    "<< hexa[10].getPlace() <<"     \\ "<< endl;
    //     cout << "(29)    "<< internal << setw(2)<<hexa[8].getNum()<<"    (25)---(26)             (27)---(28)      "<< internal << setw(2)<<hexa[10].getNum()<<"    (34)"<< endl;
    //     cout << " \\            /          \\            /         \\             / "<< endl;
    //     cout << "  \\          /     "<<hexa[11].getPlace()<<"     \\          /     "<< hexa[12].getPlace()<<"     \\          / "<< endl;
    //     cout << "   (30)---(31)     "<< internal << setw(2)<<hexa[11].getNum()<<"      (32)---(33)      "<< internal << setw(2)<<hexa[12].getNum()<<"    (35)---(36)"<< endl;
    //     cout << "   /         \\             /         \\           /           \\ "<< endl;
    //     cout << "  /     "<<hexa[13].getPlace()<<"     \\           /     "<< hexa[14].getPlace()<<"     \\         /      "<<hexa[15].getPlace()<<"     \\ "<< endl;
    //     cout << "(41)    "<< internal << setw(2)<<hexa[13].getNum()<<"    (37)---(38)      "<< internal << setw(2)<<hexa[14].getNum()<<"     (39)---(40)     "<< internal << setw(2)<<hexa[15].getNum()<<"      (48)"<< endl;
    //     cout << " \\            /          \\            /         \\             / "<< endl;
    //     cout << "  \\          /     "<< hexa[16].getPlace()<<"      \\          /    "<< hexa[17].getPlace()<<"     \\           / "<< endl;
    //     cout << "   (42)---(43)      "<< internal << setw(2)<<hexa[16].getNum()<<"     (44)---(45)     "<< internal << setw(2)<<hexa[17].getNum()<<"    (46)---(47)"<< endl;
    //     cout << "             \\            /          \\           /   "<< endl;
    //     cout << "              \\          /     "<< hexa[18].getPlace() <<"     \\         /  "<< endl;
    //     cout << "               (49)---(50)      "<< internal << setw(2)<<hexa[18].getNum()<<"     (51)---(52)  "<< endl;
    //     cout << "                         \\            /"<< endl;
    //     cout << "                          \\          /"<< endl;
    //     cout << "                           (53)---(54)"<< endl;

        
    // }

    void Board::boardStutus(){
        vector<vector<string>> bobo(31, vector<string>(34, "  "));
        bobo[0][15] = ver[0].getVer();
        bobo[0][18] = ver[1].getVer();
        bobo[0][16] = roads[0].getRoad();
        bobo[0][17] = roads[0].getRoad();

        bobo[1][14] = roads[1].getRoad();
        bobo[1][19] = roads[2].getRoad();
        bobo[2][13] = roads[1].getRoad();
        bobo[2][20] = roads[2].getRoad();
        
        bobo[3][12] = ver[2].getVer();
        bobo[3][21] = ver[3].getVer();
        bobo[3][11] = roads[3].getRoad();
        bobo[3][10] = roads[3].getRoad();
        bobo[3][9] = ver[9].getVer();
        bobo[3][22] = roads[4].getRoad();
        bobo[3][23] = roads[4].getRoad();
        bobo[3][24] = ver[10].getVer();

        bobo[4][13] = roads[6].getRoad();
        bobo[4][20] = roads[7].getRoad();
        bobo[5][14] = roads[6].getRoad();
        bobo[5][19] = roads[7].getRoad();
        bobo[4][8] = roads[5].getRoad();
        bobo[5][7] = roads[5].getRoad();
        bobo[4][25] = roads[8].getRoad();
        bobo[5][26] = roads[8].getRoad();

        bobo[6][3] = ver[14].getVer();
        bobo[6][4] = roads[9].getRoad();
        bobo[6][5] = roads[9].getRoad();
        bobo[6][6] = ver[8].getVer();
        bobo[6][15] = ver[4].getVer();
        bobo[6][16] = roads[10].getRoad();
        bobo[6][17] = roads[10].getRoad();
        bobo[6][18] = ver[5].getVer();
        bobo[6][27] = ver[11].getVer();
        bobo[6][28] = roads[11].getRoad();
        bobo[6][29] = roads[11].getRoad();
        bobo[6][30] = ver[20].getVer();

        bobo[7][2] = roads[12].getRoad();
        bobo[8][1] = roads[12].getRoad();
        bobo[7][7] = roads[13].getRoad();
        bobo[8][8] = roads[13].getRoad();
        bobo[7][14] = roads[14].getRoad();
        bobo[8][13] = roads[14].getRoad();
        bobo[7][19] = roads[15].getRoad();
        bobo[8][20] = roads[15].getRoad();
        bobo[7][26] = roads[16].getRoad();
        bobo[8][25] = roads[16].getRoad();
        bobo[7][31] = roads[17].getRoad();
        bobo[8][32] = roads[17].getRoad();

        bobo[9][0] = ver[15].getVer();
        bobo[9][9] = ver[7].getVer();
        bobo[9][10] = roads[18].getRoad();
        bobo[9][11] = roads[18].getRoad();
        bobo[9][12] = ver[6].getVer();
        bobo[9][21] = ver[13].getVer();
        bobo[9][22] = roads[19].getRoad();
        bobo[9][23] = roads[19].getRoad();
        bobo[9][24] = ver[12].getVer();
        bobo[9][33] = ver[21].getVer();

        bobo[10][1] = roads[20].getRoad();
        bobo[11][2] = roads[20].getRoad();
        bobo[10][8] = roads[21].getRoad();
        bobo[11][7] = roads[21].getRoad();
        bobo[10][13] = roads[22].getRoad();
        bobo[11][14] = roads[22].getRoad();
        bobo[10][20] = roads[23].getRoad();
        bobo[11][19] = roads[23].getRoad();
        bobo[10][25] = roads[24].getRoad();
        bobo[11][26] = roads[24].getRoad();
        bobo[10][32] = roads[25].getRoad();
        bobo[11][31] = roads[25].getRoad();

        bobo[12][3] = ver[16].getVer();
        bobo[12][4] = roads[26].getRoad();
        bobo[12][5] = roads[26].getRoad();
        bobo[12][6] = ver[17].getVer();
        bobo[12][15] = ver[18].getVer();
        bobo[12][16] = roads[27].getRoad();
        bobo[12][17] = roads[27].getRoad();
        bobo[12][18] = ver[19].getVer();
        bobo[12][27] = ver[23].getVer();
        bobo[12][28] = roads[28].getRoad();
        bobo[12][29] = roads[28].getRoad();
        bobo[12][30] = ver[22].getVer();

        bobo[13][2] = roads[29].getRoad();
        bobo[14][1] = roads[29].getRoad();
        bobo[13][7] = roads[30].getRoad();
        bobo[14][8] = roads[30].getRoad();
        bobo[13][14] = roads[31].getRoad();
        bobo[14][13] = roads[31].getRoad();
        bobo[13][19] = roads[32].getRoad();
        bobo[14][20] = roads[32].getRoad();
        bobo[13][26] = roads[33].getRoad();
        bobo[14][25] = roads[33].getRoad();
        bobo[13][31] = roads[34].getRoad();
        bobo[14][32] = roads[34].getRoad();

        bobo[15][0] = ver[28].getVer();
        bobo[15][9] = ver[24].getVer();
        bobo[15][10] = roads[35].getRoad();
        bobo[15][11] = roads[35].getRoad();
        bobo[15][12] = ver[25].getVer();
        bobo[15][21] = ver[26].getVer();
        bobo[15][22] = roads[36].getRoad();
        bobo[15][23] = roads[36].getRoad();
        bobo[15][24] = ver[27].getVer();
        bobo[15][33] = ver[33].getVer();

        bobo[16][1] = roads[37].getRoad();
        bobo[17][2] = roads[37].getRoad();
        bobo[16][8] = roads[38].getRoad();
        bobo[17][7] = roads[38].getRoad();
        bobo[16][13] = roads[39].getRoad();
        bobo[17][14] = roads[39].getRoad();
        bobo[16][20] = roads[40].getRoad();
        bobo[17][19] = roads[40].getRoad();
        bobo[16][25] = roads[41].getRoad();
        bobo[17][26] = roads[41].getRoad();
        bobo[16][32] = roads[42].getRoad();
        bobo[17][31] = roads[42].getRoad();

        bobo[18][3] = ver[29].getVer();
        bobo[18][4] = roads[43].getRoad();
        bobo[18][5] = roads[43].getRoad();
        bobo[18][6] = ver[30].getVer();
        bobo[18][15] = ver[31].getVer();
        bobo[18][16] = roads[44].getRoad();
        bobo[18][17] = roads[44].getRoad();
        bobo[18][18] = ver[32].getVer();
        bobo[18][27] = ver[34].getVer();
        bobo[18][28] = roads[45].getRoad();
        bobo[18][29] = roads[45].getRoad();
        bobo[18][30] = ver[35].getVer();

        bobo[19][2] = roads[46].getRoad();
        bobo[20][1] = roads[46].getRoad();
        bobo[19][7] = roads[47].getRoad();
        bobo[20][8] = roads[47].getRoad();
        bobo[19][14] = roads[48].getRoad();
        bobo[20][13] = roads[48].getRoad();
        bobo[19][19] = roads[49].getRoad();
        bobo[20][20] = roads[49].getRoad();
        bobo[19][26] = roads[50].getRoad();
        bobo[20][25] = roads[50].getRoad();
        bobo[19][31] = roads[51].getRoad();
        bobo[20][32] = roads[51].getRoad();

        bobo[21][0] = ver[40].getVer();
        bobo[21][9] = ver[36].getVer();
        bobo[21][10] = roads[52].getRoad();
        bobo[21][11] = roads[52].getRoad();
        bobo[21][12] = ver[37].getVer();
        bobo[21][21] = ver[38].getVer();
        bobo[21][22] = roads[53].getRoad();
        bobo[21][23] = roads[53].getRoad();
        bobo[21][24] = ver[39].getVer();
        bobo[21][33] = ver[47].getVer();

        bobo[22][1] = roads[54].getRoad();
        bobo[23][2] = roads[54].getRoad();
        bobo[22][8] = roads[55].getRoad();
        bobo[23][7] = roads[55].getRoad();
        bobo[22][13] = roads[56].getRoad();
        bobo[23][14] = roads[56].getRoad();
        bobo[22][20] = roads[57].getRoad();
        bobo[23][19] = roads[57].getRoad();
        bobo[22][25] = roads[58].getRoad();
        bobo[23][26] = roads[58].getRoad();
        bobo[22][32] = roads[59].getRoad();
        bobo[23][31] = roads[59].getRoad();

        bobo[24][3] = ver[41].getVer();
        bobo[24][4] = roads[60].getRoad();
        bobo[24][5] = roads[60].getRoad();
        bobo[24][6] = ver[42].getVer();
        bobo[24][15] = ver[43].getVer();
        bobo[24][16] = roads[61].getRoad();
        bobo[24][17] = roads[61].getRoad();
        bobo[24][18] = ver[44].getVer();
        bobo[24][27] = ver[45].getVer();
        bobo[24][28] = roads[62].getRoad();
        bobo[24][29] = roads[62].getRoad();
        bobo[24][30] = ver[46].getVer();

        bobo[25][7] = roads[63].getRoad();
        bobo[26][8] = roads[63].getRoad();
        bobo[25][14] = roads[64].getRoad();
        bobo[26][13] = roads[64].getRoad();
        bobo[25][19] = roads[65].getRoad();
        bobo[26][20] = roads[65].getRoad();
        bobo[25][26] = roads[66].getRoad();
        bobo[26][25] = roads[66].getRoad();

        bobo[27][9] = ver[48].getVer();
        bobo[27][10] = roads[67].getRoad();
        bobo[27][11] = roads[67].getRoad();
        bobo[27][12] = ver[49].getVer();
        bobo[27][21] = ver[50].getVer();
        bobo[27][22] = roads[68].getRoad();
        bobo[27][23] = roads[68].getRoad();
        bobo[27][24] = ver[51].getVer();

        bobo[28][13] = roads[69].getRoad();
        bobo[29][14] = roads[69].getRoad();
        bobo[28][20] = roads[70].getRoad();
        bobo[29][19] = roads[70].getRoad();

        bobo[30][15] = ver[52].getVer();
        bobo[30][16] = roads[71].getRoad();
        bobo[30][17] = roads[71].getRoad();
        bobo[30][18] = ver[53].getVer();

        bobo[2][17] = hexa[0].getPlace();
        bobo[3][17] = hexa[0].getNumString();
        bobo[8][17] = hexa[4].getPlace();
        bobo[9][17] = hexa[4].getNumString();
        bobo[20][17] = hexa[14].getPlace();
        bobo[21][17] = hexa[14].getNumString();
        bobo[26][17] = hexa[18].getPlace();
        bobo[27][17] = hexa[18].getNumString();

        bobo[5][11] = hexa[1].getPlace();
        bobo[6][11] = hexa[1].getNumString();
        bobo[11][11] = hexa[6].getPlace();
        bobo[12][11] = hexa[6].getNumString();
        bobo[17][11] = hexa[11].getPlace();
        bobo[18][11] = hexa[11].getNumString();
        bobo[23][11] = hexa[16].getPlace();
        bobo[24][11] = hexa[16].getNumString();

        bobo[5][23] = hexa[2].getPlace();
        bobo[6][23] = hexa[2].getNumString();
        bobo[11][23] = hexa[7].getPlace();
        bobo[12][23] = hexa[7].getNumString();
        bobo[17][23] = hexa[12].getPlace();
        bobo[18][23] = hexa[12].getNumString();
        bobo[23][23] = hexa[17].getPlace();
        bobo[24][23] = hexa[17].getNumString();

        bobo[8][5] = hexa[3].getPlace();
        bobo[9][5] = hexa[3].getNumString();
        bobo[20][5] = hexa[13].getPlace();
        bobo[21][5] = hexa[13].getNumString();
        bobo[14][5] = hexa[8].getPlace();
        bobo[15][5] = hexa[8].getNumString();

        bobo[8][29] = hexa[5].getPlace();
        bobo[9][29] = hexa[5].getNumString();
        bobo[20][29] = hexa[15].getPlace();
        bobo[21][29] = hexa[15].getNumString();
        bobo[14][29] = hexa[10].getPlace();
        bobo[15][29] = hexa[10].getNumString();
        

        for(int i=0; i<31; i++){
            for(int j=0; j<34; j++){
                cout << bobo[i][j];
            }
            cout <<endl;
        }
    }
    
}