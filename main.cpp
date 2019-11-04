#include <bits/stdc++.h>
using namespace std;


struct wf{
    int a, p, h;//age, pretty, haogan
    string w;//waifuname
};
void save(unsigned short saveID, int saveAge, float saveHaogan, string saveName, int savePretty);
wf load(unsigned short loadID);
void wfshow();
//以上为文字养成系统游戏的（未优化的）存读档

void showtext(string);
void showtext(string,int);
//这个是伪gal对话框读取

int main(){

    showtext("text001",3);
}

void showtext(string filename){//显示文字
    const string filetype = ".txt";
    string str;
    ifstream temp((filename+filetype).c_str());
    if(!temp){
        cout << "Open Failed!" << endl;
        exit(1);
    }
    while(!temp.eof()){
        temp >> str;
        cout << str << endl;
    }
}

void showtext(string filename,int lines){//显示文字&行数限制
    const string filetype = ".txt";
    string str;
    ifstream temp((filename+filetype).c_str());
    if(!temp){
        cout << "Open Failed!" << endl;
        exit(1);
    }
    short t = 0;
    while(!temp.eof()){
        temp >> str;
        cout << str << endl;
        t++;
        if(t==lines){
            t=0;//多人对话换行，后来可以改为cls
            cin.get();//等待玩家输入
        }
    }
    cout << "File ended.";
}

void save(unsigned short saveID, int saveAge, float saveHaogan, string saveName, int savePretty){
    string str;
    stringstream ss;
    ss << saveID;
    ss >> str;
    ofstream temp(str.c_str());
    temp << saveAge << endl << saveHaogan << endl << saveName << endl << savePretty;//没优化
    temp.close();
}
wf load(unsigned short loadID){
    wf a;
    string str;
    stringstream ss;
    ss << loadID;
    ss >> str;
    ifstream temp(str.c_str());//没做打开错误检测
    temp >> a.a >> a.h >> a.w >> a.p;//没优化
    temp.close();
    return a;
}
void wfshow(){//直接调用即可使用存档功能
    wf laopo;
    int age = 0, pretty = 0;
    float haogan = 0;
    string waifu;
    unsigned short sID = 0;
    cout << "请输入你虚拟老婆的年龄：";//没有真实老婆 我哭了
    cin >> age;//懒得做输入错误检测了，一个while(!cin.get(ch))的事
    cout << "请输入你虚拟老婆的魅力值：";
    cin >> pretty;
    cout << "请输入你虚拟老婆的名字：";
    cin >> waifu;
    cout << "请输入你虚拟老婆的好感度：";
    cin >> haogan;
    cout << "接下来将保存存档。请输入存档id：";
    cin >> sID;
    save(sID,age,haogan,waifu,pretty);
    cout << "已保存为" << sID << "号存档。" << endl
    << "接下来将读取" << sID << "号存档。";//保存为根目录下一个无后缀名文件，文件名为sID
    laopo = load(sID);
    cout << endl << endl << "你刚才输入的如下所示：" << endl
    << "姓名：" << laopo.w << endl << "年龄：" << laopo.a << endl
    << "好感度：" << laopo.h << endl << "魅力值：" << laopo.p;
}

