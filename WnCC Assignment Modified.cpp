#include<iostream>
//#include<WnCC funtion.h>
using namespace std;
struct participant{
    int roll_no;
    int skill[5];
    int no_of_skills;
    bool selected;
    int eligible;   //0 not eligible; 1 eligible; 2 eligible with mentoring
};
struct project{
    char name[100];
    int skill[5];
    int roles; //number of rolls
    int remark; //-1 can't be completed; 0 not completed; 1 completed
};
int n, m;
int main(){
    //taking participant name and skill entry
    cin >> n;
    participant a[n];
    for(int i=0; i<n; i++){
        cin >> a[i].roll_no;
        a[i].no_of_skills=0;
        for(int j=0; j<5; j++){
            cin >> a[i].skill[j];
            if(a[i].skill[j])
                a[i].no_of_skills++;
        }
        a[i].selected=false;
        a[i].eligible=0;
    }

    cout << "ops";
    //taking project name and skill requirement entry
    cin >> m;
    project b[m];
    for(int i=0; i<n; i++){
        cout <<endl <<  i << "\t";
        cin >> b[i].name;
        b[i].roles=0;
        for(int j=0; j<5; j++){
            cin >> b[i].skill[j];
            if(b[i].skill[j])
                b[i].roles++;
        }
        b[i].remark=0;
    }

    int project_completed=0;

    //processing
    while(true){
        int x=-1;
        for(int i=0; i<m; i++){
            if(x==-1){
                if(b[i].remark==0)  x=i;
            }else{
                if(b[i].roles<b[x].roles && b[i].remark==0)
                    x=i;
            }
        }
        if(x==-1){
            break;
        }

        //so far we've got the project with minimum number of roles which is not completed
        
        int eligible_num=0;
        for(int i=0; i<5; i++){
            if(b[x].skill[i]){
                for(int j=0; j<n; j++){
                    if(a[j].skill[i]>=b[x].skill[i] && a[j].selected==false && a[j].eligible==0){
                        a[j].eligible=1;
                        eligible_num++;
                        break;
                    }
                }
            }
        }
        //cout << eligible_num << endl;
        //remarking the project
        if(eligible_num==b[x].roles){
            for(int i=0; i<n; i++){
                if(a[i].eligible==1){
                    a[i].selected=true;
                }
            }
            b[x].remark=1;
            project_completed++;
        }else{
            b[x].remark=-1;
        }

        //resetting individual eligibility
        for(int i=0; i<n; i++){
            a[i].eligible=0;
        }

        //cout << x << " " << b[x].remark << endl;
    }
    
    //cout << "project completed : ";
    cout << project_completed;

}
