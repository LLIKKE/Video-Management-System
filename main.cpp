#include "programa.h"
 int Video::total=0;
ProgramaGroup PG;
ConsumerGroup CG;
string _Author_= "1200604012 ����";
void homepage(){
    cout<<"*��ӭ��ʹ��cnu������Ƶϵͳ*"<<endl;
    cout<<"*1) ����Ա"<<endl;
    cout<<"*2) ��ͨ�û�"<<endl;
    cout<<"*3) �˳�ϵͳ"<<endl;
    cout<<"*��ѡ���¼�û�����"<<endl;
}
void admin_page(){
    cout<<"��������Ȩ�ޣ�"<<endl;
    cout<<"*1) ��Ŀ����"<<endl;
    cout<<"*2) ���ݹ���"<<endl;
    cout<<"*3) �û�����"<<endl;
    cout<<"*4) ���ʼ�¼����"<<endl;
    cout<<"*5) ͳ��"<<endl;
    cout<<"*6) �˳�"<<endl;
    cout<<"����������[1-6]: "<<endl;
}
void account_page(){
    cout<<"*��ӭ������Ƶ����ģ��..."<<endl;
    cout<<"*1) ����û�"<<endl;
    cout<<"*2) �û��б�"<<endl;
    cout<<"*3) ɾ����Ƶ"<<endl;
    cout<<"*4) �����û�"<<endl;
    cout<<"*5) ������һ��"<<endl;
    cout<<"����������[1-5]: "<<endl;
}
void programa_page(){
    cout<<"*��ӭ������Ŀ����ģ��..."<<endl;
    cout<<"*1) �����Ŀ"<<endl;
    cout<<"*2) ɾ����Ŀ"<<endl;
    cout<<"*3) ��ѯ��Ŀ"<<endl;
    cout<<"*4) �鿴��Ŀ�б�"<<endl;
    cout<<"*5) ������һ��"<<endl;
    cout<<"����������[1-5]: "<<endl;
}
void video_page(){
    cout<<"*��ӭ������Ƶ���ݹ���ģ��..."<<endl;
    cout<<"*1) �����Ƶ"<<endl;
    cout<<"*2) ɾ����Ƶ"<<endl;
    cout<<"*3) ��ѯ��Ƶ"<<endl;
    cout<<"*4) �鿴��Ƶ�б�"<<endl;
    cout<<"*5) ������һ��"<<endl;
    cout<<"����������[1-5]: "<<endl;
}
void consumer_page(){
    cout<<"*��ӭ�����û��ռ�..."<<endl;
    cout<<"*1) ��Ƶ�б�"<<endl;
    cout<<"*2) �鿴��Ƶ����"<<endl;
    cout<<"*3) �޸�����"<<endl;
    cout<<"*4) ������һ��"<<endl;
    cout<<"����������[1-5]: "<<endl;
}
void consumer_select(){
    cout<<"*��ѡ�����Ƶ�ľ�������..."<<endl;
    cout<<"*1) ��Ƶ����"<<endl;
    cout<<"*2) ��Ƶ����"<<endl;
    cout<<"*3) ��Ƶʱ��"<<endl;
    cout<<"*4) ��Ƶ�շ����"<<endl;
    cout<<"*5) ��Ƶ����"<<endl;
    cout<<"*6) ������һ��"<<endl;
    cout<<"����������[1-6]: "<<endl;
}
void recard_manage(){
    cout<<"*��ӭʹ�÷��ʼ�¼����..."<<endl;
    cout<<"*1) ��ѯ�û����ʼ�¼"<<endl;
    cout<<"*2) ɾ���û����ʼ�¼"<<endl;
    cout<<"*3) ������һ��"<<endl;
    cout<<"����������[1-3]: "<<endl;
}
void count_page(){
    cout<<"*��ӭʹ��ͳ�ƹ���..."<<endl;
    cout<<"*1) ��ѯ�û�����"<<endl;
    cout<<"*2) ��ѯ��Ƶ����"<<endl;
    cout<<"*3) ��ѯ��������"<<endl;
    cout<<"*4) ������һ��"<<endl;
    cout<<"����������[1-4]: "<<endl;
}
int keyboard(){
    int k;
    cin>>k;
    return k;
}
int page_keyborad(void (*page)(),int (*keyb)()){
    page();
    return keyb();
}
void Programa_management_sys(){
    while (true){
        switch (page_keyborad(programa_page,keyboard)) {
            case 1:{
                cout<<"*��ӭʹ��������Ŀ����..."<<endl;
                cout<<"*��������Ŀ����: "<<endl;
                programa_type t;
                cin>>t;
                Programa p(t);
                PG.Add_programa(t,p);
                break;
            }
            case 2:{
                cout<<"*��ӭʹ��ɾ����Ŀ����..."<<endl;
                cout<<"*�������ɾ����Ŀ����: "<<endl;
                programa_type t;
                cin>>t;
                PG.Delet_program(t);
                break;
            }
            case 3:{
                cout<<"*��ӭʹ�ò�ѯ��Ŀ����..."<<endl;
                cout<<"*���������ѯ��Ŀ����: "<<endl;
                programa_type t;
                cin>>t;
                PG.Search_programa(t);
                break;

            }
            case 4:{
                cout<<"*������ȫ����Ŀ�б�..."<<endl;
                PG.Show_program_list();
                break;
            }

            default:
                return;
        }
    }
}
void Account_management_sys(){

    while (true)
    {
    switch (page_keyborad(account_page,keyboard))
        {
        case 1: {
            cout << "*��ӭʹ�������û�����..." << endl;

            Consumer C;
            cin >> C;
            CG.Add_consumer(C);
            cout<<"*�û������"<<endl;
            break;
        }
            case 2:{
                cout<<"*����Ϊϵͳ��ȫ���û�����Ϣ..."<<endl;
                CG.Show_consumerlist();
                cout<<"*������..."<<endl;
                break;
            }
            case 3:{
                cout << "*��ӭʹ��ɾ���û�����..."<<endl;
                cout<<"*�������ɾ���û��˺ţ�"<<endl;
                string ac;
                cin>>ac;
                if(CG.Delet_consumer(ac))
                    cout<<"*�û���ɾ��"<<endl;
                else
                    cout<<"*δ�ҵ����û������������˻�"<<endl;
                break;
            }
            case 4:{
                cout << "*�û����湦��..."<<endl;
                cout<<"*������������û��˺ţ�"<<endl;
                string ac;
                cin>>ac;
                CG.warming(ac);
                break;}
            case 5:
                return;
        }
    }
    return;
}
void Video_management_sys(){
    while (true){
        switch (page_keyborad(video_page,keyboard)) {
            case 1:
            {cout<<"*��ӭʹ��������Ƶ����..."<<endl;
                cout<<"*������������Ŀ����: "<<endl;
                programa_type t;
                cin>>t;
                Video v;
                cin>>v;
                PG.Add_programa_video(t,v);
                break;}
            case 2:
            {
                programa_type s;
                string t;
                cout<<"*��ӭʹ��ɾ����Ƶ����..."<<endl;
                cout<<"*������������Ŀ����: "<<endl;
                cin>>s;
                cout<<"*������������Ƶ����: "<<endl;
                cin>>t;
                PG.Delet_programa_video(s,t);

            }
            case 3:{
                programa_type s;
                string t;
                cout<<"*��ӭʹ�ò�ѯ��Ƶ����..."<<endl;
                cout<<"*���������ѯ��Ŀ����: "<<endl;
                cin>>s;
                cout<<"*���������ѯ��Ƶ����: "<<endl;
                cin>>t;
                PG.Search_programa_video(s,t);
                break;
            }
            case 4:{
                PG.Show_programa_video_list();
                break;
            }
            case 5:
                return;
            default:
                cout<<"*����������[1-5]"<<endl;
        }
    }
}
void Count_sys(){
    while(true){
        switch (page_keyborad(count_page,keyboard)) {
            case 1:
            {
                cout<<"*ϵͳ�ܹ��û�����Ϊ��"<<CG.ConsumerGroup_size()<<endl;
                break;
            }
            case 2:
            {
                cout<<"*ϵͳ�ܹ���Ƶ����Ϊ��"<<PG.ProgramaGroup_size()<<endl;
                break;
            }
            case 3:
            {
                string ac;
                cout<<"*�������û��˺�"<<endl;
                cin>>ac;
                auto it=CG.Search_account(ac);
                cout<<"�û�"<<ac<<" ����������"<<it->warnings()<<endl;
                break;
            }
            case 4:
                return;
            default:
                cout<<"*����������[1-4]"<<endl;
        }
    }
}
void Record_sys(Consumer &C){
    while (true){
        switch (page_keyborad(recard_manage,keyboard)) {
            case 1:
            {
                cout<<"*��Ϊ����������¼��Ƶ����б�..."<<endl;
                C.Show_record();
                cout<<"*�����¼������"<<endl;
                break;
            }
            case 2:
            {
                cout<<"*��Ϊ����������¼��Ƶ����б�..."<<endl;
                C.Delet_record();
                cout<<"*��ɾ�����û������¼"<<endl;
                break;
            }
            case 3:
                return;
            default:
                cout<<"*����������[1-3]"<<endl;
        }
    }
}
void Admin_sys(){
    string iaccount;
    string ikey;
    input:
    cout<<"�������˺ţ�";
    cin>>iaccount;
    cout<<"���������룺";
    cin>>ikey;
    Accountistrator A(iaccount,ikey);
    if(!A.sucess){
        goto input;
    }

    while (true) {
        switch (page_keyborad(admin_page, keyboard)) {
            case 1:
            {
                Programa_management_sys();
                break;
            }
            case 2:
            {
                Video_management_sys();
                break;
            }
            case 3:
            {
                Account_management_sys();
                break;
            }
            case 4:
            {
                cout<<"*���������ѯ�����¼���˻��˺�..."<<endl;
                string ac;
                cin>>ac;
                auto p=CG.Search_account(ac);
                Record_sys(*p);
                break;
            }
            case 5:
            {
                Count_sys();
                break;
            }
            case 6:
                return ;
            default:
                cout<<"*��������[1-6]"<<endl;
        }
    }

}
void Consumer_video_sys(const Video& v){
    while(true){
        switch (page_keyborad(consumer_select,keyboard)) {
            case 1:
            {
                video_type vt=v.Get_Type();
                cout<<"*����Ƶ������Ϊ��"<<vt<<endl;
                break;
            }
            case 2:
            {
                cout<<"*����Ƶ������Ϊ��"<<v.Get_Name()<<endl;
                break;
            }
            case 3:
            {
                cout<<"*����Ƶ��ʱ��Ϊ��"<<v.Get_Length()<<endl;
                break;
            }
            case 4:
            {
                string free;
                if(v.Get_Free())
                    free="true";
                else
                    free="false";
                cout<<"*����Ƶ���շ����Ϊ��"<<free<<endl;
                break;
            }
            case 5:
            {
                cout<<"*����Ƶ�Ľ���Ϊ��"<<v.Get_Introduce()<<endl;
                break;
            }
            case 6:{
                return;
            }
            default:
                cout<<"*����������[1-6]"<<endl;
        }
    }
    return;
}
void Consumer_sys(){
    string caccount;
    string ckey;
    input:
    cout<<"�������˺ţ�";
    cin>>caccount;
    cout<<"���������룺";
    cin>>ckey;
    auto p=CG.Log_In(caccount,ckey);
    if(!CG.sucess){
        goto input;
    }
    while (true) {
        switch (page_keyborad(consumer_page, keyboard)) {
            case 1: {
                cout << "*����Ϊȫ����Ŀ����Ƶ����..." << endl;
                PG.Show_programa_video_list();
                cout << "*��ӡ���" << endl;
                break;
            }
            case 2: {
                string n;
                programa_type c;
                cout << "*��������Ƶ������Ŀ" << endl;
                cin >> c;
                cout << "*��������Ƶ����" << endl;
                cin >> n;
                const Video v = PG.Con_search_programa_video(c, n);
                p->Add_record(v.Get_code());
                Consumer_video_sys(v);
                break;
            }
            case 3: {
                cout << "*�����޸��˻�����" << endl;
                cout << "*�������µ��˻�����" << endl;
                string s;
                cin >> s;
                p->Edit_key(s);
                break;
            }
            case 4:
                return;
            default:
                cout << "*��������[1-4]" << endl;

        }
    }
}
int main() {
    string _Author_= "1200604012 ����";

    while (true){
        switch (page_keyborad(homepage,keyboard)) {
            case 1:
                Admin_sys();
                break;
            case 2:
                Consumer_sys();
                break;
            case 3:
                return 0;
            default:
                cout<<"*����������[1-3]"<<endl;
        }
    }

}

