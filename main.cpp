#include "programa.h"
 int Video::total=0;
ProgramaGroup PG;
ConsumerGroup CG;
string _Author_= "1200604012 李珂";
void homepage(){
    cout<<"*欢迎您使用cnu在线视频系统*"<<endl;
    cout<<"*1) 管理员"<<endl;
    cout<<"*2) 普通用户"<<endl;
    cout<<"*3) 退出系统"<<endl;
    cout<<"*请选择登录用户类型"<<endl;
}
void admin_page(){
    cout<<"具有如下权限："<<endl;
    cout<<"*1) 栏目管理"<<endl;
    cout<<"*2) 内容管理"<<endl;
    cout<<"*3) 用户管理"<<endl;
    cout<<"*4) 访问记录管理"<<endl;
    cout<<"*5) 统计"<<endl;
    cout<<"*6) 退出"<<endl;
    cout<<"请输入命令[1-6]: "<<endl;
}
void account_page(){
    cout<<"*欢迎进入视频管理模块..."<<endl;
    cout<<"*1) 添加用户"<<endl;
    cout<<"*2) 用户列表"<<endl;
    cout<<"*3) 删除视频"<<endl;
    cout<<"*4) 警告用户"<<endl;
    cout<<"*5) 返回上一级"<<endl;
    cout<<"请输入命令[1-5]: "<<endl;
}
void programa_page(){
    cout<<"*欢迎进入栏目管理模块..."<<endl;
    cout<<"*1) 添加栏目"<<endl;
    cout<<"*2) 删除栏目"<<endl;
    cout<<"*3) 查询栏目"<<endl;
    cout<<"*4) 查看栏目列表"<<endl;
    cout<<"*5) 返回上一级"<<endl;
    cout<<"请输入命令[1-5]: "<<endl;
}
void video_page(){
    cout<<"*欢迎进入视频内容管理模块..."<<endl;
    cout<<"*1) 添加视频"<<endl;
    cout<<"*2) 删除视频"<<endl;
    cout<<"*3) 查询视频"<<endl;
    cout<<"*4) 查看视频列表"<<endl;
    cout<<"*5) 返回上一级"<<endl;
    cout<<"请输入命令[1-5]: "<<endl;
}
void consumer_page(){
    cout<<"*欢迎进入用户空间..."<<endl;
    cout<<"*1) 视频列表"<<endl;
    cout<<"*2) 查看视频内容"<<endl;
    cout<<"*3) 修改密码"<<endl;
    cout<<"*4) 返回上一级"<<endl;
    cout<<"请输入命令[1-5]: "<<endl;
}
void consumer_select(){
    cout<<"*请选择该视频的具体内容..."<<endl;
    cout<<"*1) 视频类型"<<endl;
    cout<<"*2) 视频名称"<<endl;
    cout<<"*3) 视频时长"<<endl;
    cout<<"*4) 视频收费情况"<<endl;
    cout<<"*5) 视频介绍"<<endl;
    cout<<"*6) 返回上一级"<<endl;
    cout<<"请输入命令[1-6]: "<<endl;
}
void recard_manage(){
    cout<<"*欢迎使用访问记录管理..."<<endl;
    cout<<"*1) 查询用户访问记录"<<endl;
    cout<<"*2) 删除用户访问记录"<<endl;
    cout<<"*3) 返回上一级"<<endl;
    cout<<"请输入命令[1-3]: "<<endl;
}
void count_page(){
    cout<<"*欢迎使用统计管理..."<<endl;
    cout<<"*1) 查询用户数量"<<endl;
    cout<<"*2) 查询视频数量"<<endl;
    cout<<"*3) 查询警告数量"<<endl;
    cout<<"*4) 返回上一级"<<endl;
    cout<<"请输入命令[1-4]: "<<endl;
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
                cout<<"*欢迎使用增加栏目功能..."<<endl;
                cout<<"*请输入栏目类型: "<<endl;
                programa_type t;
                cin>>t;
                Programa p(t);
                PG.Add_programa(t,p);
                break;
            }
            case 2:{
                cout<<"*欢迎使用删除栏目功能..."<<endl;
                cout<<"*请输入待删除栏目类型: "<<endl;
                programa_type t;
                cin>>t;
                PG.Delet_program(t);
                break;
            }
            case 3:{
                cout<<"*欢迎使用查询栏目功能..."<<endl;
                cout<<"*请输入待查询栏目类型: "<<endl;
                programa_type t;
                cin>>t;
                PG.Search_programa(t);
                break;

            }
            case 4:{
                cout<<"*以下是全部栏目列表..."<<endl;
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
            cout << "*欢迎使用增加用户功能..." << endl;

            Consumer C;
            cin >> C;
            CG.Add_consumer(C);
            cout<<"*用户已添加"<<endl;
            break;
        }
            case 2:{
                cout<<"*以下为系统中全部用户的信息..."<<endl;
                CG.Show_consumerlist();
                cout<<"*输出完毕..."<<endl;
                break;
            }
            case 3:{
                cout << "*欢迎使用删除用户功能..."<<endl;
                cout<<"*请输入待删除用户账号："<<endl;
                string ac;
                cin>>ac;
                if(CG.Delet_consumer(ac))
                    cout<<"*用户已删除"<<endl;
                else
                    cout<<"*未找到该用户，请检查输入账户"<<endl;
                break;
            }
            case 4:{
                cout << "*用户警告功能..."<<endl;
                cout<<"*请输入待警告用户账号："<<endl;
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
            {cout<<"*欢迎使用增加视频功能..."<<endl;
                cout<<"*请输入待添加栏目类型: "<<endl;
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
                cout<<"*欢迎使用删除视频功能..."<<endl;
                cout<<"*请输入待添加栏目名称: "<<endl;
                cin>>s;
                cout<<"*请输入待添加视频名称: "<<endl;
                cin>>t;
                PG.Delet_programa_video(s,t);

            }
            case 3:{
                programa_type s;
                string t;
                cout<<"*欢迎使用查询视频功能..."<<endl;
                cout<<"*请输入待查询栏目名称: "<<endl;
                cin>>s;
                cout<<"*请输入待查询视频名称: "<<endl;
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
                cout<<"*请重新输入[1-5]"<<endl;
        }
    }
}
void Count_sys(){
    while(true){
        switch (page_keyborad(count_page,keyboard)) {
            case 1:
            {
                cout<<"*系统总共用户数量为："<<CG.ConsumerGroup_size()<<endl;
                break;
            }
            case 2:
            {
                cout<<"*系统总共视频数量为："<<PG.ProgramaGroup_size()<<endl;
                break;
            }
            case 3:
            {
                string ac;
                cout<<"*请输入用户账号"<<endl;
                cin>>ac;
                auto it=CG.Search_account(ac);
                cout<<"用户"<<ac<<" 警告数量："<<it->warnings()<<endl;
                break;
            }
            case 4:
                return;
            default:
                cout<<"*请重新输入[1-4]"<<endl;
        }
    }
}
void Record_sys(Consumer &C){
    while (true){
        switch (page_keyborad(recard_manage,keyboard)) {
            case 1:
            {
                cout<<"*将为您输出浏览记录视频序号列表..."<<endl;
                C.Show_record();
                cout<<"*浏览记录输出完毕"<<endl;
                break;
            }
            case 2:
            {
                cout<<"*将为您输出浏览记录视频序号列表..."<<endl;
                C.Delet_record();
                cout<<"*已删除该用户浏览记录"<<endl;
                break;
            }
            case 3:
                return;
            default:
                cout<<"*请重新输入[1-3]"<<endl;
        }
    }
}
void Admin_sys(){
    string iaccount;
    string ikey;
    input:
    cout<<"请输入账号：";
    cin>>iaccount;
    cout<<"请输入密码：";
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
                cout<<"*请输入待查询浏览记录的账户账号..."<<endl;
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
                cout<<"*重新输入[1-6]"<<endl;
        }
    }

}
void Consumer_video_sys(const Video& v){
    while(true){
        switch (page_keyborad(consumer_select,keyboard)) {
            case 1:
            {
                video_type vt=v.Get_Type();
                cout<<"*该视频的类型为："<<vt<<endl;
                break;
            }
            case 2:
            {
                cout<<"*该视频的名称为："<<v.Get_Name()<<endl;
                break;
            }
            case 3:
            {
                cout<<"*该视频的时长为："<<v.Get_Length()<<endl;
                break;
            }
            case 4:
            {
                string free;
                if(v.Get_Free())
                    free="true";
                else
                    free="false";
                cout<<"*该视频的收费情况为："<<free<<endl;
                break;
            }
            case 5:
            {
                cout<<"*该视频的介绍为："<<v.Get_Introduce()<<endl;
                break;
            }
            case 6:{
                return;
            }
            default:
                cout<<"*请重新输入[1-6]"<<endl;
        }
    }
    return;
}
void Consumer_sys(){
    string caccount;
    string ckey;
    input:
    cout<<"请输入账号：";
    cin>>caccount;
    cout<<"请输入密码：";
    cin>>ckey;
    auto p=CG.Log_In(caccount,ckey);
    if(!CG.sucess){
        goto input;
    }
    while (true) {
        switch (page_keyborad(consumer_page, keyboard)) {
            case 1: {
                cout << "*以下为全部栏目和视频内容..." << endl;
                PG.Show_programa_video_list();
                cout << "*打印完毕" << endl;
                break;
            }
            case 2: {
                string n;
                programa_type c;
                cout << "*请输入视频所在栏目" << endl;
                cin >> c;
                cout << "*请输入视频名称" << endl;
                cin >> n;
                const Video v = PG.Con_search_programa_video(c, n);
                p->Add_record(v.Get_code());
                Consumer_video_sys(v);
                break;
            }
            case 3: {
                cout << "*正在修改账户密码" << endl;
                cout << "*请输入新的账户密码" << endl;
                string s;
                cin >> s;
                p->Edit_key(s);
                break;
            }
            case 4:
                return;
            default:
                cout << "*重新输入[1-4]" << endl;

        }
    }
}
int main() {
    string _Author_= "1200604012 李珂";

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
                cout<<"*请重新输入[1-3]"<<endl;
        }
    }

}

