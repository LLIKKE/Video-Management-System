#ifndef FINAL_USER_H
#define FINAL_USER_H

#include "library.h"


const string admin = "admin";
const string key = "123456";

//const string acount[3]={"aa","bb","cc"};
//const string acount_key[3]={"11","22","33"};
//const string name[3]={"one","two","three"};


class User{
protected:
    string Name;
    string Account;
    string Key;
public:
    User(){}
    User(string ad,string ke,string na){
        Account=ad;
        Key=ke;
        Name=na;

    }
    string Get_account(){
        return Account;
    }
    string Get_key(){
        return Key;
    }
    string Get_name(){
        return Name;
    }
    bool Edit_name(string na){
        Name=na;
        return true;
    }
    bool Edit_account(string ac){
        Account=ac;
        return true;
    }
    bool Edit_key(string ke){
        Key=ke;
        return true;
    }
};

class Accountistrator: protected User{
private:
public:
    bool sucess;
    Accountistrator(string ad,string ke,string na="Admin"):User(ad,ke,na){


    if(ad==admin && ke==key)
    {
        cout << "*��ӭ��admin�����Ľ�ɫ�ǹ���Ա��" << endl;
        sucess = true;
    }else{
        cout << "*�û��������������,����������" << endl;
        sucess = false;
    }


    }
};

class Consumer:protected User{
private:
    int warning;
    vector<int> record;
public:
    Consumer(){}
    Consumer(string ad,string ke,string na):User(ad,ke,na){
        warning=0;
    }
    bool Show_record(){
        cout<<"�����¼[";
        for(auto i:record){
            cout<<i<<' ';
        }
        cout<<"]"<<endl;
        return true;
    }
    bool Delet_record(){
        record.clear();
        return true;
    }
    bool Add_warning(){
        warning++;
        return true;
    }
    bool Add_record(int i){
        record.push_back(i);
        return true;
    }
    bool Edit_key(string ke){
        Key=ke;
        return true;
    }
    int warnings(){
        return warning;
    }
    /*Consumer(const Consumer &sensor) {
        this->Edit_name(sensor.Name);
        this->Edit_account(sensor.Account);
        this->Edit_key(sensor.Key);
    }*/
    Consumer &operator=(const Consumer &c) {
        if(this == &c) {
            return *this;
        }
        Name=c.Name;
        Account=c.Account;
        Key=c.Key;
        return *this;
    }
    using User::Get_name;
    using User::Get_account;
    using User::Get_key;
    using User::Edit_account;
    using User::Edit_key;
    using User::Edit_name;
    friend ostream& operator<<(ostream &stream, Consumer &ob);
    friend istream& operator>>(istream &stream, Consumer &ob);
};
ostream& operator<<(ostream &stream, Consumer &ob){
    stream<<"�û��ǳƣ�"<<ob.Get_name()<<" �û����룺"<<ob.Get_key()<<" �û��˺ţ�"<<ob.Get_account()<<endl;
    return stream;
}
istream& operator>>(istream &stream, Consumer &ob){
    string na,ac,ke;
    cout<<"�������û�����";
    cin>>ac;
    cout<<"���������룺";
    cin>>ke;
    cout<<"�������ǳƣ�";
    cin>>na;
    ob.Edit_name(na);
    ob.Edit_key(ke);
    ob.Edit_account(ac);
    return stream;
}

class ConsumerGroup{
private:
    vector<Consumer> CGroup;
    int sum;
    bool isNameMatch(Consumer v, string& targetName) {
        return v.Get_name() == targetName;
    }
    void read_txt_consumer(const string& path){
        ifstream file(path);
        string line;
        cout<<"*�����ݿ��ж�ȡ�Ѵ����û��б�..."<<endl;
        while (getline(file, line)) {
            vector<string> parts = split(line, ' ', false);
            string part1 = parts[0];
            string part2 = parts[1];
            string part3 = parts[2];
            cout<<"*���ڶ�ȡ��"<<sum+1<<"���û���Ϣ: "<<endl;
            Consumer C(part1,part2,part3);
            CGroup.push_back(C);
            sum++;
            //Show_consumerlist();
        }
        cout<<"*��ȡ����"<<endl;
        file.close();
    }
public:
    bool sucess;

    ConsumerGroup(string path="E:\\project\\c++\\final\\consumer.txt"){
        sum=0;
        read_txt_consumer(path);
    }
    auto Search_account(string ac){
        auto it = find_if(CGroup.begin(), CGroup.end(), [&ac](Consumer &p) {return p.Get_account() == ac;});
        if(it!=CGroup.end())
        {
            return it;
        }
        else
            cout<<"*δ�ҵ�";
    }
    auto Log_In(string ac,string ke){

        auto it = find_if(CGroup.begin(), CGroup.end(), [&ac](Consumer &p) {return p.Get_account() == ac;});
        sucess= false;
        if(it==CGroup.end()){
            cout<<"*δ�ҵ����û�������������"<<endl;
        } else{

            if(it->Get_key()==ke){
                sucess= true;
                cout<<"*��½�ɹ�����������ǻ�Ա"<<endl;
                return it;
            }
        }
    }
    int ConsumerGroup_size() const{
        return sum;
    }
    int Consumer_num(){
        return CGroup.size();
    }
    bool Add_consumer(Consumer s){
        CGroup.push_back(s);
        sum++;
        return true;
    }
    bool Delet_consumer(string ac){
        auto it = CGroup.erase(std::remove_if(CGroup.begin(), CGroup.end(), [&](const Consumer& v) {
            return isNameMatch(v, ac);
        }), CGroup.end());
        if(it!=CGroup.end()){
            sum--;
            return true;}
        else
            return false;
    }
    bool Show_consumerlist(){
        int i=0;
        for (vector<Consumer>::iterator it = CGroup.begin(); it != CGroup.end(); ++it) {
            cout<<"******��"<<i++<<"���û�********"<<endl;
            cout << *it <<endl;
        }
        return true;
    }

    bool warming(string ac){
        auto it = find_if(CGroup.begin(), CGroup.end(), [&ac](Consumer &p) {return p.Get_account() == ac;});
        if(it==CGroup.end()){
            cout<<"*δ�ҵ����û�������������"<<endl;
            return false;
        } else{
            it->Add_warning();
            cout<<"*����ɹ�"<<endl;
            return true;
        }
    }
};


#endif //FINAL_USER_H
