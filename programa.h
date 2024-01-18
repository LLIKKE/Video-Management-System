//
// Created by lenovo on 2023/7/5.
//

#ifndef FINAL_PROGRAMA_H
#define FINAL_PROGRAMA_H
#include "user.h"

class Video{
private:
    enum video_type Type;
    string Name;
    string Introduce;
    double Length;
    bool Free;
    int code_name;
    static int total;
public:
    Video(){
        Type=NONE;
        Name="NONE";
        Length=0;
        Free= false;
        code_name = total++;
    }
    Video(enum video_type t,string n,string i,double l,bool f):
            Type(t),Name(n),Introduce(i),Length(l),Free(f){
        code_name = total++;
    }
    enum video_type Get_Type()const{
        return Type;
    }
    int Get_code() const{
        return code_name;
    }
    string Get_Name()const{
        return Name;
    }
    string Get_Introduce()const{
        return Introduce;
    }
    double Get_Length()const{
        return Length;
    }
    bool Get_Free()const{
        return Free;
    }
    bool Edit_Type(enum video_type t){
        Type=t;
        return true;
    }
    bool Edit_Name(string n){
        Name=n;
        return true;
    }
    bool Edit_Introduce(string i){
        Introduce=i;
        return true;
    }
    bool Edit_Length(double l){
        Length=l;
        return true;
    }
    bool Edit_Free(bool f){
        Free=f;
        return true;
    }
    friend ostream& operator<<(ostream &stream, Video &ob);
    friend istream& operator>>(istream &stream, Video &ob);
};
ostream& operator<<(ostream &stream, Video &ob){
    video_type t=ob.Get_Type();
    string free;
    if(ob.Get_Free())
        free="true";
    else
        free="false";
    stream<<"number: "<<ob.Get_code()<<" video type: "<<t<<" name: "<<ob.Get_Name()<<endl;
    stream<<"introduce: "<<ob.Get_Introduce()<<" time_length: "<<ob.Get_Length()<<" free: "<<free<<endl;
    return stream;
}
istream& operator>>(istream &stream, Video &ob){
    string st;
    video_type v;
    double l;
    cout<<"����������Ƶ���͡���Ƶ���ơ���Ƶ���ȡ��Ƿ��շѡ���Ƶ���ܣ�"<<endl;
    cout<<"ע�⣺"<<endl<<"��Ƶ�����������Ӧ���ţ�"<<endl<<"1)��Ӱ��2)���Ӿ磬3)����Ƶ��4)���"<<endl;
    stream>>v;
    cout<<"������Ƶ���ͣ�";
    ob.Edit_Type(v);
    cout<<"������Ƶ���ƣ�";
    stream>>st;
    ob.Edit_Name(st);
    cout<<"������Ƶ���ȣ�";
    stream>>l;
    ob.Edit_Length(l);
    cout<<"������Ƶ�Ƿ���ѣ�";
    stream>>st;
    ob.Edit_Free(st=="true");
    stream>>st;
    cout<<"������Ƶ���ܣ�";
    ob.Edit_Introduce(st);
    return stream;
}

class Programa{
private:
    enum programa_type Type;
    vector<Video> Videolist;
    bool isNameMatch(Video v, string& targetName) {
        return v.Get_Name() == targetName;
    }
    bool Find_video(string na){
        string Na=na;
        auto it = find_if(Videolist.begin(), Videolist.end(), [&Na](Video &p) {return p.Get_Name() == Na;});
        return true;
    }
public:
    Programa(){}
    Programa(enum programa_type t){
        Type=t;
    }
    programa_type Get_promgType(){
        return Type;
    }
    vector<Video> Get_videolist(){
        return Videolist;
    }
    bool Add_video(Video v){
        Videolist.push_back(v);
        return true;
    }
    bool Delet_video(string na){
        auto it = Videolist.erase(std::remove_if(Videolist.begin(), Videolist.end(), [&](const Video& v) {
            return isNameMatch(v, na);
        }), Videolist.end());
        if(it!=Videolist.end())
            return true;
        else
            return false;
    }
    bool Search_video(string na){
        auto it = find_if(Videolist.begin(), Videolist.end(), [&na](Video &p) {return p.Get_Name() == na;});
        if(it!=Videolist.end())
        {
            cout<<*it<<endl;
            return true;

        }
        else
            return false;
    }
    Video Con_search_video(string na){
        auto it = find_if(Videolist.begin(), Videolist.end(), [&na](Video &p) {return p.Get_Name() == na;});
        if(it!=Videolist.end())
        {
            return *it;
        }
        else
            cout<<"*δ�ҵ�";
        return *it;
    }
    bool Edit_Type(enum programa_type t){
        Type=t;
        return true;
    }
    int Programa_num(){
        return Videolist.size();
    }
    bool Show_video_list(){
        for(auto p:Videolist){
            cout<<p<<endl;
        }
        return true;
    }
    friend ostream& operator<<(ostream &stream, Programa &ob);
    friend istream& operator>>(istream &stream, Programa &ob);

};

ostream& operator<<(ostream &stream, Programa &ob){
    stream<<"program type: "<<ob.Get_promgType()<<endl;
    auto video_list = ob.Get_videolist();
    for(int i=0;i<video_list.size();i++)
        stream<<setw(5)<<video_list[i]<<endl;
    return stream;
}

istream& operator>>(istream &stream, Programa &ob){
    cout<<"����������Ŀ���ͣ�"<<endl;
    cout<<"ע�⣺"<<endl<<"��Ŀ�����������ӦӢ�ģ�"<<endl<<"��Ӱ��movie�����Ӿ�:teleplay������Ƶ:shortvideo�����:advertisement"<<endl;
    programa_type c;
    stream>>c;
    ob.Edit_Type(c);

    return stream;
}

class ProgramaGroup{
private:
    map<programa_type, Programa> prog;
    int sum;
    void read_txt_programagroup(const string& path) {
        ifstream file(path);
        string line;
        vector<string> tokens;
        programa_type t;
        int c=0;
        cout << "*�����ݿ��ж�ȡ�Ѵ�����Ŀ�б�..." << endl;
        while (getline(file, line)) {
            tokens=split(line,'(');
            bool i= false;
            for (string& token : tokens) {
                if(!i){
                    t=PT[token];
                    i = true;
                } else{
                    vector<string> to;
                    to=split(token,' ', false);
                    video_type p=VT[to[0]];
                    Video v(p,to[1],to[2],stod(to[3]),to[4]=="true");
                    prog[t].Add_video(v);
                    sum++;
                }

            }
            cout<<"*���ڶ�ȡ��"<<++c<<"����Ŀ��Ϣ..."<<endl;
        }
        cout << "*��ȡ����" << endl;
        file.close();

    }
public:

    ProgramaGroup(const string& path="E:\\project\\c++\\final\\programgroup.txt"){
        read_txt_programagroup(path);

    }
    friend ostream& operator<<(ostream &stream, ProgramaGroup &ob);
    int ProgramaGroup_size() const{
        return sum;
    }
    bool Find_program(programa_type ke){
        auto iter = prog.find(ke);
        if (iter != prog.end()) {
            // ������
            return true;
        } else {
            // ��������
            return false;
        }
    }
    bool Search_programa(programa_type ke){
        auto iter = prog.find(ke);
        if (iter != prog.end()) {
            // ������
            cout<<iter->first<<endl;
            return true;
        } else {
            // ��������
            cout<<"*����Ŀ������"<<endl;
            return false;
        }
    }
    bool Add_programa(enum programa_type t,const Programa& v){
        if(Find_program(t)){
            cout<<"*�Ѵ��ڸ���Ŀ�������ظ����"<<endl;
            return false;
        }
        prog.insert({t,v});
        return true;
    }
    bool Delet_program(enum programa_type t){
        if(!Find_program(t)){
            cout<<"*�����ڸ���Ŀ���޷����"<<endl;
            return false;
        }
        prog.erase(t);

        return true;
    }
    bool Show_program_list(){
        for (auto iter = prog.begin(); iter != prog.end(); ++iter) {
            programa_type t=iter->first;
            cout<<t<<endl;
        }
        return true;
    }
    bool Add_programa_video(enum programa_type t,Video v){
        prog[t].Add_video(v);
        sum++;
        return true;
    }
    bool Delet_programa_video(enum programa_type t,string na){
        prog[t].Delet_video(na);
        sum--;
        return true;
    }
    bool Search_programa_video(programa_type t,string na){
        prog[t].Search_video(na);
        return true;
    }
    Video Con_search_programa_video(programa_type t,string na){
        return prog[t].Con_search_video(na);
    }
    bool Show_programa_video_list(){
        for (const auto& pair : prog) {
            prog[pair.first].Show_video_list();
        }
        return true;
    }
};
ostream& operator<<(ostream &stream, ProgramaGroup &ob){
    for(auto it : ob.prog){
        cout <<  it.second <<endl;
    }
    return stream;
}

#endif //FINAL_PROGRAMA_H
