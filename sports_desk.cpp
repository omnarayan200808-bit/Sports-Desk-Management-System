#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<limits>
using namespace std;
class Athlete{
    protected:
    int A_ID;
    string A_Name;
    int age;
    string sports_type;
    public:
    Athlete(int A_ID,string A_Name,int age,string sports_type):A_ID(A_ID),A_Name(A_Name),age(age),sports_type(sports_type){}
    Athlete():A_ID(0),A_Name("RAM"),age(0),sports_type("ALL"){}
    virtual ~Athlete(){
        //destructor
    }
    int getA_ID ()const{
        return A_ID;
    }
    string getA_Name()const{
        return A_Name;
    }
    int getage() const{
        return age;
    }
    string getsports_type()const{
        return sports_type;
    }
    virtual double calculateRating()const=0;
    virtual void displaycard()const=0;
};
class BadmintonPlayer:public Athlete{
    private:
    string racket_model;
    string string_tension;
    int match_played;
    int matches_won;
public:
    BadmintonPlayer(int A_ID,string A_Name,int age,string racket_model,string string_tension,int match_played,int matches_won):Athlete(A_ID,A_Name,age,"Badminton"),racket_model(racket_model),string_tension(string_tension),match_played(match_played),matches_won(matches_won){}
    BadmintonPlayer():Athlete(0,"RAM",0,"Badminton"),racket_model("ZR100"),string_tension("18LBS"),match_played(0),matches_won(0){}
    double calculateRating() const override{
        double NET=((double)matches_won/match_played)*100;
        if(match_played==0){
            cout<<"No details found,BEGINNER"<<endl;
            return 1.0;
        }
        double rating=1.0;
        if( NET>=90){
            cout<<"!!!!⭐️⭐️⭐️⭐️★ ELITE PLAYER 😈 😈!!!!"<<endl;
            rating=4.8 ;
        }
        else if(NET>=75){
            cout<<"_-_-_-_ ⭐️⭐️⭐️⭐️ ADVANCED PLAYER 🤠 🤠_-_-_-_"<<endl;
            rating=4.0 ;
        }
        else if(NET>=50){
            cout<<"_^_^_^_ ⭐️⭐️⭐️ INTERMEDIATE PLAYER 😄 😄_^_^_^_"<<endl;
            rating=3.0 ; 
        }
        else if(NET>=25){
            cout<<"->^->^->^ ⭐️⭐️ ADVANCE BEGINNERS PLAYER ☺️ ☺️ <-^<-^<-^"<<endl;
            rating=2.0;
        }
        else{
            cout<<"#### ⭐️★ NOVICE PLAYERS 🥺 😑 ####"<<endl;
            rating=1.2;
        }
        return rating;
    }
    void displaycard() const override{
        cout<<"_=_=_=_BADMINTION PLAYER DETAILS IS HERE _=_=_=_"<<endl;
        cout<<endl;
        cout<<"ATHLETE ID OF PLAYER->"<<A_ID<<endl;
        cout<<"PLAYER NAME->"<<A_Name<<endl;
        cout<<"PLAYER AGE->"<<age<<endl;
        cout<<"Racket_Model="<<racket_model<<endl;
        cout<<"String_tension="<<string_tension<<endl;
        cout<<"Match_played="<<match_played<<endl;
        cout<<"Match_won="<<matches_won<<endl;
        cout<<"Rating="<<calculateRating()<<endl;
        cout<<"_=_=_=_ END _=_=_=_"<<endl;
        cout<<endl;
    }
};
class Cricketplayer:public Athlete{
    private:
    string Speciality;
    int run_scored;
    int wicket;
    int innings;
public:
    Cricketplayer(int A_ID,string A_Name,int age,string Speciality,int run_scored,int wicket,int innings):Athlete(A_ID, A_Name ,age ,"Cricket"),Speciality(Speciality),run_scored(run_scored),wicket(wicket),innings(innings){}
    Cricketplayer():Athlete(0,"RAM",0,"Cricket"),Speciality("umpair"),run_scored(0),wicket(0),innings(0){}
    double calculateRating() const override{
        int total=((double)run_scored/innings);
        if(innings==0){
            cout<<"NO details found❔,🆕"<<endl;
            return 1.0;
        }
        double rating=1.0;
        if(Speciality=="Batsman"|| Speciality=="BATSMAN"){
            if(total>=90){
                cout<<"!!!! ⭐️⭐️⭐️⭐️★ LEGENDARY PLAYER 😈 😈!!!!"<<endl;
                rating=4.8;
            }
            else if(total>=75){
                cout<<"#-_#-_#-_ ⭐️⭐️⭐️⭐️ WORLD CLASS 🙂 🙂 #-_#-_#-_"<<endl;
                rating=4.0;
            }
            else if(total>=50){
                cout<<"_^-^_^-^_ ⭐️⭐️⭐️ DEPENDEABLE PLAYER 🥳 🥳 _^-^_^-^_"<<endl;
                rating=3.0;
            }
            else if(total>=25){
                cout<<"#### ⭐️⭐️ VULNERABLE PLAYER 😳 😳####"<<endl;
                rating=2.0;
            }
            else{
                cout<<"->^->^-> ⭐️★ TALINDER 😓 😓<-^<-^<-^"<<endl;
                rating=1.2;
            }
            return rating;
        }
        int final=((double)wicket/innings);
        if(Speciality=="Bowler"|| Speciality=="BOWLER"){
            if(final>=4){
                cout<<"!!!! ⭐️⭐️⭐️⭐️★ ELITE STRICKE BOWELER 😈 😈!!!!"<<endl;
                rating=4.5;
            }
            else if(final>=3){
                cout<<"#-_#-_#-_ ⭐️⭐️⭐️⭐️★ WORLD CLASS 🙂 🙂 #-_#-_#-_"<<endl;
                rating=4.0;
            }
            else if(final>=2){
                cout<<"_^-^_^-^_ ⭐️⭐️⭐️ DEPENDEABLE PLAYER 🥳 🥳 _^-^_^-^_"<<endl;

                rating=3.0;
            }
            else if(final>=1){
                cout<<"#### ⭐️⭐️ INCONSISTENT PLAYER 😳 😳 ####"<<endl;
                rating=2.0;
            }
            else{
               cout<<"->^->^-> ⭐️★ PART-TIMER 😓 😓 <-^<-^<-^"<<endl;
               rating=1.2; 
            }
            return rating;
        }
        int result=((double)run_scored/innings)+((double)20*wicket/innings);
        if(Speciality=="All-Rounder"){
            if(result>=80){
                cout<<"!!!! ⭐️⭐️⭐️⭐️★ ELITE STRICKE BOWELER 😈 😈!!!!"<<endl;
                rating=4.5;
            }
            else if(result>=60){
                cout<<"#-_#-_#-_ ⭐️⭐️⭐️⭐️  WORLD CLASS 🙂 🙂 #-_#-_#-_"<<endl;
                rating=4.0;
            }
            else if(result>=40){
                cout<<"_^-^_^-^_  ⭐️⭐️⭐️ DEPENDEABLE PLAYER 🥳 🥳 _^-^_^-^_"<<endl;
                rating=3.0;
            }
            else if(result>=25){
                cout<<"#### ⭐️⭐️ INCONSISTENT PLAYER 😳 😳####"<<endl;
                rating=2.0;
            }
            else{
                cout<<"->^->^-> ⭐️★ PART-TIMER 😓 😓 <-^<-^<-^"<<endl;
                rating=1.2;
            }
           

        }
        return rating;
    }
    void displaycard() const override{
        cout<<"================== CRICKET PLAYER DETAILS HERE=================="<<endl;
        cout<<endl;
        cout<<"ATHLETE ID OF PLAYER->"<<A_ID<<endl;
        cout<<"PLAYER NAME->"<<A_Name<<endl;
        cout<<"PLAYER AGE->"<<age<<endl;
        cout<<"SPECIALITY="<<Speciality<<endl;
        if(Speciality=="Batsman"){
            cout<<"RUN SCORED="<<run_scored<<endl;
        }
        else if(Speciality=="Bowler"){
            cout<<"WICKET TAKEN="<<wicket<<endl;
        }
        else{
            cout<<"RUN SCORED="<<run_scored<<endl;
            cout<<"WICKET TAKEN="<<wicket<<endl;
        }
        cout<<"TOTAL MATCH PLAYED="<<innings<<endl;
        cout<<"RATING="<<calculateRating()<<endl;
        cout<<"================================================================"<<endl;
        cout<<endl;
    }
};
class sportsdeskManager{
    vector<Athlete*>roster;
    int capacity=0;
    int roster_size=10;
    bool chek=false;
    public:
    ~sportsdeskManager() {
        for (Athlete* athlete : roster) {
            delete athlete;
        }
        roster.clear();
    }
    void Entery(Athlete* athlete){
        if(!athlete)return;
        if(capacity>=roster_size){
            cout<<"==============================================================="<<endl;
            cout<<"ERROR:❌❌ ROSTER GET OVERFLOW,NOT ADD MORE ATHLETE SORRY ❌❌"<<endl;
            cout<<"=============================================================="<<endl;
            cout<<endl;
            delete athlete;
            return;
        }
        for(const Athlete*a:roster){
            if(a->getA_ID()==athlete->getA_ID()){
                cout<<"▫️ ERROR:🚫 Athlete with ID " << athlete->getA_ID() << " already exists! 🚫" << endl;
                delete athlete;
                cout<<endl;
                chek=true;
                return;
            }
        }
        roster.push_back(athlete);
        capacity++;
        cout<<"♦️ ✅ Athlete "<<athlete->getA_Name()<<"  with ID number "<<athlete->getA_ID()<<" get added sucessfully ✅"<<endl;
        cout<<endl;
    }
    void displaychoise(){
        cout<<"=========== ENTER YOUR CHOISE ============="<<endl;
        cout<<endl;
        cout<<" ☺️ ☺️ ☺️ ☺️ WELCOME TO HELP DESK ☺️ ☺️ ☺️ ☺️ "<<endl;
        cout<<endl;
        cout<<"▶ ENTER 1 FOR BADMINTON(🏸) REGISTRATION."<<endl;
        cout<<endl;
        cout<<"▶ ENTER 2 FOR CRICKET(🏏) REGISTRATION."<<endl;
        cout<<endl;
        cout<<"▶ ENTER 3 FOR CHECK REGISTERED MEMBERS DETAILS(📋) AND RANKING!."<<endl;
        cout<<endl;
        cout<<"▶ ENTER 4 FOR CHECK NO.OF REGISTRATION."<<endl;
        cout<<endl;
        cout<<"▶ ENTER 5 FOR GENERATE OVERALL REGISTRATION DETAILS."<<endl;
        cout<<endl;
        cout<<"▶ ENTER 6 FOR DISPLAY OVERALL REGISTRATION DETAILS."<<endl;
        cout<<endl;
        cout<<"▶ ENTER 7 FOR EXIT 🚶‍➡️ ."<<endl;
        cout<<endl;
        cout<<"========== 🏁🏁🏁FINISH🏁🏁🏁 =========="<<endl;
        cout<<endl;
        cout<<"💥 SELECT 1-7 FOR CHECK DETAILS !"<<endl;
        cout<<endl;
        cout<<"💥 REQUEST TO PRESS 7 FOR EXIT AFTER USING INTERFACE👍👍"<<endl;
        cout<<endl;
    }
    void registerMenu(){
        chek=true;
        int choice=0;
        displaychoise();
        while(chek){
            cout<<endl;
            cout<<"-=-=-=-=🙏🙏🙏WELCOME TO HELP DESK🙏🙏🙏=-=-=-=-="<<endl;
            cout<<endl;
            cout<<"~_~ ENTER YOUR CHOISE ~_~"<<endl;
            cin>>choice;
            if (cin.fail()){
                cin.clear(); // Clears the error state flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the invalid character
                continue;
            }
            switch(choice){
                case 1:{
                    cout<<" ~_~ 🙏🙏🙏 WELCOME TO BADMINTION CLUB 🙏🙏🙏 ~_~ "<<endl;
                    int A_ID ,age,match_played,matches_won;
                    string A_NAME, racket_model,string_tension;
                    cout<<"ENTER ID NUMBER:";
                    cin>>A_ID;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"ENTER YOUR NAME:";
                    getline(cin,A_NAME);
                    cout<<"ENTER Age:";
                    cin>>age;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"ENTER Racket Model Name:";
                    getline(cin,racket_model);
                    cout<<"Enter racket tenssion->";
                    getline(cin,string_tension);
                    cout<<"TOTAL MATCHES PLAYED->";
                    cin>>match_played;
                    cout<<"TOTAL MATCHES WON->";
                    cin>>matches_won;
                    Entery(new BadmintonPlayer(A_ID,A_NAME, age, racket_model,string_tension,match_played,matches_won));
                    break;

                } 
                case 2:{
                    cout<<" ~_~ 🙏🙏🙏 WELCOME TO CRICKET CLUB 🙏🙏🙏 ~_~ "<<endl;
                    int A_ID, innings, run_scored, wicket,age;
                    string A_NAME,Speciality;
                    cout<<"ENTER ID NUMBER:";
                    cin>>A_ID;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"ENTER YOUR NAME:";
                    getline(cin,A_NAME);
                    cout<<"ENTER Speciality(batsman,bowler,All-Rounder)->";
                    cin>>Speciality;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"ENTER AGE:";
                    cin>>age;
                    cout<<"TOTAL MATCHES PLAYED->";
                    cin>>innings;
                    if(Speciality=="Batsman"){
                        cout<<"ENTER RUN SCORED->";
                        cin>>run_scored;
                    }
                    else if(Speciality=="Bolwer"){
                        cout<<"ENTER WICKETS TAKEN->";
                        cin>>wicket;
                    }
                    else {
                        cout<<"ENTER RUN SCORED->";
                        cin>>run_scored;
                        cout<<"ENTER WICKETS TAKEN->";
                        cin>>wicket;
                    }
                    Entery(new Cricketplayer(A_ID,A_NAME,age,Speciality,run_scored,wicket,innings));
                    break;
                }
                case 3:{
                    int A_ID;
                    cout<<"Enter 🆔->";
                    cin>>A_ID;
                    displayAll(A_ID);
                    break;
                }
                case 4:{
                    size();
                    break;
                }
                case 5:{
                    generatelegal();
                    break;
                }
                case 6:{
                    displayrecipt();
                    break;
                }
                case 7:
                cout<<"THANK U 🙏 FOR USEING OUR HELP DESK PLEASE VISIT AGAIN!"<<endl;
                chek=false;
                break;
                default:
                cout<<"ERROR❌:🙂‍↕️ PRESS VALID NUMBERS FOR CHECK DETAILS! TRY AGAIN"<<endl;
               
                break;
                
            }
        }
    }
    void displayAll(int A_ID) const {
        bool flag=false;
        cout << "================ TOURNAMENT ROSTER ================"<<endl;
        cout<<endl;
        for (int i=0;i<roster.size();i++){
            if(roster[i]->getA_ID()==A_ID){
                roster[i]->displaycard();
                flag=true;
                break;
            }
        }
       if(flag==false){
                cout<<"❌ A_TD NOT FOUND IN ROSTER!⭕️"<<endl;
            }
    }
    void size(){
        cout << "Total Registered Athletes: " << roster.size() << "/" << roster_size << "\n\n";
    }
    void generatelegal(){
        ofstream filewriter("tournament_roster.txt");
        if(filewriter.is_open()){
            filewriter<<"_-_-_-_YOUR CHEKLIST HERE_-_-_-_"<<endl;
            for(const Athlete*a:roster){
                filewriter<<"A_ID->"<<a->getA_ID()<<endl;
                filewriter<<"A_NAME->"<<a->getA_Name()<<endl;
                filewriter<<"SPORTS_TYPE->"<<a->getsports_type()<<endl;
                filewriter<<endl;
                // filewriter<<"RATING OF PLAYER IS->"<<a->calculateRating()<<endl; 
                // cout<<"x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-"<<endl;
            }
            cout<<endl;
            filewriter.close();
            cout<<"----LEGAL REGISTRATION SUCESSFULLY(tournament_roster.txt)----"<<endl;
            cout<<"✅ SAVE in disk ✅ "<<endl;
            
        }
        else {
            cout<<"❌ Either file not exist or something went wrong,sorry ❌"<<endl;
        }
    }
    void displayrecipt(){
        fstream filereader("tournament_roster.txt");
        string line;
        if(filereader.is_open()){
            cout<<"_-_-_-_ START READING CHEKLIST_-_-_-_"<<endl;
            cout<<endl;
            while(getline(filereader,line)){
                cout<<line<<endl;
            }
            cout<<endl;
            filereader.close();
            cout<<"-_-_-_- CURRENT STATUS-_-_-_-"<<endl;
            cout<<"✅ Reading completed ✅"<<endl; 
            cout<<endl;
        }
        else{
                cout<<" ❌Either file not exist or something went wrong ❌"<<endl;
        } 
    }
    

};
int main(){
    sportsdeskManager desk1;
    desk1.registerMenu();
    
}