#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 25

int T[MAX][MAX];
int R[MAX][MAX];

int N,M,K,C;

// �����¿� (�������� ����)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int near_t = 0;
int near_e = 0;

struct PAIR{
    int a;
    int b;
    PAIR(int x, int y){
        a = x;
        b = y;
    }
};
vector<PAIR> MT;

struct Killer{
    int a;   // ������ x��ǥ
    int b;   // ������ y��ǥ
    int cnt;   // �����ϴ� ������
};
vector<Killer> Killers;

// �밢�� (������ ����)
int rx[4] = {-1, 1, -1, 1};
int ry[4] = {1, 1, -1, -1};

// ������ �߾���
int kx, ky;

// ���ŵǴ� ���� ������
int result = 0;


// �Է�
void Input(){
    
    freopen("input.txt", "r", stdin);
    cin>>N>>M>>K>>C;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>T[i][j];
            R[i][j] = 0;
        }
    }
    // Initialize R[][] �� �Բ� ����
}


// ������ ����
void TreeGrowing(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if(T[i][j] <= 0) continue;   // ��ĭ/��
            
            near_t = 0;
            for(int d=0; d<4; d++){
                int xx = i + dx[d];
                int yy = j + dy[d];
                
                if((xx<0)||(xx>=N)||(yy<0)||(yy>=N)) continue;  // ���� ����
                
                if((T[xx][yy] > 0)&&(R[xx][yy] == 0)){
                    near_t++;
                }
                
            }
            
            T[i][j] += near_t;
            
        }
    }
}


// ������ ����
void MultiplyTrees(){
    
    int NT[MAX][MAX] = {0};
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if(T[i][j] <= 0) continue;   // ��ĭ/��
            
            near_e = 0;
            MT.clear();
            
            for(int d=0; d<4; d++){
                int xx = i + dx[d];
                int yy = j + dy[d];
                
                if((xx<0)||(xx>=N)||(yy<0)||(yy>=N)) continue;  // ���� ����
                
                if((T[xx][yy] == 0)&&(R[xx][yy] == 0)){  // ��ĭ�̸鼭 ����������
                    near_e++;
                    MT.push_back(PAIR(xx,yy));
                }
            }
            
            for(int mt=0; mt<MT.size(); mt++){
                int mul = (T[i][j] / near_e);
                NT[MT[mt].a][MT[mt].b] += mul;
            }
        }
    }
    
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if(T[i][j] == -1) continue;   // ��
            T[i][j] += NT[i][j];
        }
    }
}



bool Comp(Killer A, Killer B){
    if(A.cnt > B.cnt) return true;
    else if(A.cnt == B.cnt){
        if(A.a < B.a) return true;
        else if(A.a == B.a){
            if(A.b < B.b) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

// ������ ��ġ (kx, ky) ����
void RPosition(){
    int max_count = 0;
    int count = 0;
    Killers.clear();
    kx = 0;
    ky = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            if(T[i][j] < 0) continue;   // �� �Ѿ
            
            count = T[i][j];   // ����/��ĭ/������
            if(T[i][j] > 0){  // ���� -> ������ ��������
                for(int d=0; d<4; d++){
                    for(int k=1; k<=K; k++){
                        int xx = i + (rx[d]*k);
                        int yy = j + (ry[d]*k);
                        
                        if((xx<0)||(xx>=N)||(yy<0)||(yy>=N)) break;  // ���� ����
                        if((T[xx][yy] <= 0)||(R[xx][yy] > 0)) break;   // ��ĭ/��/������ �Ѿ
                        count += T[xx][yy];
                    }
                }
            }
            else{} // ��ĭ/������ -> ������ ���������� ����
            if(max_count <= count){
                if(max_count == count){
                    max_count = count;
                    Killers.push_back({i,j,max_count});
                }
                if(max_count < count){
                    max_count = count;
                    Killers.clear();
                    Killers.push_back({i,j,max_count});
                }
            }
            
        }
    }
    
    sort(Killers.begin(), Killers.end(), Comp);
    kx = Killers[0].a;
    ky = Killers[0].b;
    
}


// ������ �Ѹ���
void RLocate(){
    
    // ������ �߽� ��ǥ (kx, ky)
    result += T[kx][ky];
    T[kx][ky] = 0;
    R[kx][ky] = C+1;
    
    // ������ ��������
    for(int d=0; d<4; d++){
        for(int k=1; k<=K; k++){
            int xx = kx + (rx[d]*k);
            int yy = ky + (ry[d]*k);
            
            if((xx<0)||(xx>=N)||(yy<0)||(yy>=N)) break;  // ���� ����
            if(T[xx][yy] < 0) break;   // �� �Ѿ
            if(T[xx][yy] == 0){  // ��ĭ/������
                R[xx][yy] = C+1;
                break;
            }
            
            result += T[xx][yy];
            T[xx][yy] = 0;
            R[xx][yy] = C+1;
        }
    }
}


// ȸ���ϱ�
void Heal(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(R[i][j] > 0) R[i][j]--;
        }
    }
}


// print out maps
void Show(){

    // ���� map
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    
    
    // ������ map
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<R[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


void Simulate(){
    
    TreeGrowing();
    
    MultiplyTrees();
    
    RPosition();
    
    RLocate();
    
    Heal();
    
}


int main(){
    ios_base::sync_with_stdio(false);
    
    Input();
    
    for(int round=1; round<=M; round++){
        Simulate();
    }
    
    cout<<result<<"\n";
    return 0;
}
