/*
ID: 319055430
Email: noa.fishman@gmail.com
*/

#include "board.hpp"
using namespace std;

namespace noa{

    void Board:: biuldBoard(){
        srand(time(0));
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

    bool Board::canBuildRoad(Vertex& v1, Vertex& v2, int n){ // check that the player can build ther a road
        cout << "here  !!!" <<endl;
        int numV1 = v1.getNum(), numV2 = v2.getNum();

        if(ver[numV1 -1].getOwner() == n && ver[numV1 -1].getBuild() != 0){
            return true; // he have city or settelment in v1
            
        }
        cout << "v1 is not your"<< endl;

        if(ver[numV2 -1].getOwner() == n && ver[numV2 -1].getBuild() != 0){
            return true; // he have city or settelment in v2
        }
        cout << "v2 is not your"<< endl;

        vector<int> ro = ver[numV1 -1].gerRoads(); // get the vertex's roads numbers
        if(!ro.empty()){
            for(int i=0; i<static_cast<int>(ro.size()); i++){
                if(roads[ro[i]-1].getOwner() == n){ //check if own of the roads around this vertex belong to the player
                    return true;
                }
            }
        }else{
            cout << "empty1 ???" <<endl;
        }
        cout << "v1 roads is not your"<< endl;

        vector<int> ro2 = ver[numV2 -1].gerRoads(); // get the vertex's roads numbers
        if(!ro2.empty()){
            for(int i=0; i<static_cast<int>(ro2.size()); i++){ 
                if(roads[ro2[i]-1].getOwner() == n){ //check if own of the roads around this vertex belong to the player
                    return true;
                }
            }
        }
        else{
            cout << "empty2 ???" <<endl;
        }
        cout << "v2 roads is not your"<< endl;

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

    // void Board::printBoard(){
    //     system("gnome-terminal -- bash -c 'cat mypipe; exec bash'");

    //     std::ofstream pipe("mypipe");

    //     if (pipe.is_open()) {
            
    //     pipe << "                            (1)---(2)"<< endl;
    //     pipe << "                           /         \\ "<< endl;
    //     pipe << "                          /     " << hexa[0].getPlace()<<"     \\ "<< endl;
    //     pipe << "                (10)---(3)     "<< internal << setw(2)<<hexa[0].getNum()<<"      (4)---(11) "<< endl;
    //     pipe << "               /          \\           /          \\ "<< endl;
    //     pipe << "              /     "<<hexa[1].getPlace() <<"     \\         /     "<<hexa[2].getPlace()<<"     \\ "<< endl;
    //     pipe << "    (15)---(9)      "<< internal << setw(2)<<hexa[1].getNum()<<"      (5)---(6)     "<< internal << setw(2)<<hexa[2].getNum()<<"      (12)---(21)"<< endl;
    //     pipe << "  /           \\           /         \\            /           \\ "<< endl;
    //     pipe << " /      "<<hexa[3].getPlace()<<"     \\         /    "<<hexa[4].getPlace()<<"      \\          /     "<<hexa[5].getPlace()<<"      \\ "<< endl;
    //     pipe << "(16)   "<< internal << setw(2)<<hexa[3].getNum()<<"      (8)---(7)      "<< internal << setw(2)<<hexa[4].getNum()<<"      (14)---(13)      "<< internal << setw(2)<<hexa[5].getNum()<<"     (22)"<< endl;
    //     pipe << " \\            /         \\             /         \\             / "<< endl;
    //     pipe << "  \\          /    "<<hexa[6].getPlace()<<"      \\          /      "<<hexa[7].getPlace()<<"    \\           / "<< endl;
    //     pipe << "   (17)---(18)      "<< internal << setw(2)<<hexa[6].getNum()<<"     (19)---(20)     "<< internal << setw(2)<<hexa[7].getNum()<<"     (24)---(23)"<< endl;
    //     pipe << "  /          \\            /          \\           /           \\ "<< endl;
    //     pipe << " /     "<<hexa[8].getPlace()<<"     \\          /   Desert   \\          /    "<< hexa[10].getPlace() <<"     \\ "<< endl;
    //     pipe << "(29)    "<< internal << setw(2)<<hexa[8].getNum()<<"    (25)---(26)             (27)---(28)      "<< internal << setw(2)<<hexa[10].getNum()<<"    (34)"<< endl;
    //     pipe << " \\            /          \\            /         \\             / "<< endl;
    //     pipe << "  \\          /     "<<hexa[11].getPlace()<<"     \\          /     "<< hexa[12].getPlace()<<"     \\          / "<< endl;
    //     pipe << "   (30)---(31)     "<< internal << setw(2)<<hexa[11].getNum()<<"      (32)---(33)      "<< internal << setw(2)<<hexa[12].getNum()<<"    (35)---(36)"<< endl;
    //     pipe << "   /         \\             /         \\           /           \\ "<< endl;
    //     pipe << "  /     "<<hexa[13].getPlace()<<"     \\           /     "<< hexa[14].getPlace()<<"     \\         /      "<<hexa[15].getPlace()<<"     \\ "<< endl;
    //     pipe << "(41)    "<< internal << setw(2)<<hexa[13].getNum()<<"    (37)---(38)      "<< internal << setw(2)<<hexa[14].getNum()<<"     (39)---(40)     "<< internal << setw(2)<<hexa[15].getNum()<<"      (48)"<< endl;
    //     pipe << " \\            /          \\            /         \\             / "<< endl;
    //     pipe << "  \\          /     "<< hexa[16].getPlace()<<"      \\          /    "<< hexa[17].getPlace()<<"     \\           / "<< endl;
    //     pipe << "   (42)---(43)      "<< internal << setw(2)<<hexa[16].getNum()<<"     (44)---(45)     "<< internal << setw(2)<<hexa[17].getNum()<<"    (46)---(47)"<< endl;
    //     pipe << "             \\            /          \\           /   "<< endl;
    //     pipe << "              \\          /     "<< hexa[18].getPlace() <<"     \\         /  "<< endl;
    //     pipe << "               (49)---(50)      "<< internal << setw(2)<<hexa[18].getNum()<<"     (51)---(52)  "<< endl;
    //     pipe << "                         \\            /"<< endl;
    //     pipe << "                          \\          /"<< endl;
    //     pipe << "                           (53)---(54)"<< endl;

    //     pipe << "This output goes to the new terminal." << std::endl;
    //         pipe.close();
        
    //     }

       
    // }

      void Board::printBoard(){

        cout << "                            (1)---(2)"<< endl;
        cout << "                           /         \\ "<< endl;
        cout << "                          /     " << hexa[0].getPlace()<<"     \\ "<< endl;
        cout << "                (10)---(3)     "<< internal << setw(2)<<hexa[0].getNum()<<"      (4)---(11) "<< endl;
        cout << "               /          \\           /          \\ "<< endl;
        cout << "              /     "<<hexa[1].getPlace() <<"     \\         /     "<<hexa[2].getPlace()<<"     \\ "<< endl;
        cout << "    (15)---(9)      "<< internal << setw(2)<<hexa[1].getNum()<<"      (5)---(6)     "<< internal << setw(2)<<hexa[2].getNum()<<"      (12)---(21)"<< endl;
        cout << "  /           \\           /         \\            /           \\ "<< endl;
        cout << " /      "<<hexa[3].getPlace()<<"     \\         /    "<<hexa[4].getPlace()<<"      \\          /     "<<hexa[5].getPlace()<<"      \\ "<< endl;
        cout << "(16)   "<< internal << setw(2)<<hexa[3].getNum()<<"      (8)---(7)      "<< internal << setw(2)<<hexa[4].getNum()<<"      (14)---(13)      "<< internal << setw(2)<<hexa[5].getNum()<<"     (22)"<< endl;
        cout << " \\            /         \\             /         \\             / "<< endl;
        cout << "  \\          /    "<<hexa[6].getPlace()<<"      \\          /      "<<hexa[7].getPlace()<<"    \\           / "<< endl;
        cout << "   (17)---(18)      "<< internal << setw(2)<<hexa[6].getNum()<<"     (19)---(20)     "<< internal << setw(2)<<hexa[7].getNum()<<"     (24)---(23)"<< endl;
        cout << "  /          \\            /          \\           /           \\ "<< endl;
        cout << " /     "<<hexa[8].getPlace()<<"     \\          /   Desert   \\          /    "<< hexa[10].getPlace() <<"     \\ "<< endl;
        cout << "(29)    "<< internal << setw(2)<<hexa[8].getNum()<<"    (25)---(26)             (27)---(28)      "<< internal << setw(2)<<hexa[10].getNum()<<"    (34)"<< endl;
        cout << " \\            /          \\            /         \\             / "<< endl;
        cout << "  \\          /     "<<hexa[11].getPlace()<<"     \\          /     "<< hexa[12].getPlace()<<"     \\          / "<< endl;
        cout << "   (30)---(31)     "<< internal << setw(2)<<hexa[11].getNum()<<"      (32)---(33)      "<< internal << setw(2)<<hexa[12].getNum()<<"    (35)---(36)"<< endl;
        cout << "   /         \\             /         \\           /           \\ "<< endl;
        cout << "  /     "<<hexa[13].getPlace()<<"     \\           /     "<< hexa[14].getPlace()<<"     \\         /      "<<hexa[15].getPlace()<<"     \\ "<< endl;
        cout << "(41)    "<< internal << setw(2)<<hexa[13].getNum()<<"    (37)---(38)      "<< internal << setw(2)<<hexa[14].getNum()<<"     (39)---(40)     "<< internal << setw(2)<<hexa[15].getNum()<<"      (48)"<< endl;
        cout << " \\            /          \\            /         \\             / "<< endl;
        cout << "  \\          /     "<< hexa[16].getPlace()<<"      \\          /    "<< hexa[17].getPlace()<<"     \\           / "<< endl;
        cout << "   (42)---(43)      "<< internal << setw(2)<<hexa[16].getNum()<<"     (44)---(45)     "<< internal << setw(2)<<hexa[17].getNum()<<"    (46)---(47)"<< endl;
        cout << "             \\            /          \\           /   "<< endl;
        cout << "              \\          /     "<< hexa[18].getPlace() <<"     \\         /  "<< endl;
        cout << "               (49)---(50)      "<< internal << setw(2)<<hexa[18].getNum()<<"     (51)---(52)  "<< endl;
        cout << "                         \\            /"<< endl;
        cout << "                          \\          /"<< endl;
        cout << "                           (53)---(54)"<< endl;


    }
    
}