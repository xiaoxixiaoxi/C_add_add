#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct WavData{
//    访问权限
public:
    int16_t* data;
    long size;

    WavData(){
        data=NULL;
        size=0;
    }
};


void loadWavFile(const char* fname,WavData *ret){
    FILE* fp=fopen(fname,"rb");
    if(fp){
        char id[5];
        int32_t size;
        int16_t format_tag,channels,block_align,bits_per_sample;
        int32_t format_length,sample_rate,avg_bytes_sec,data_size;

        fread(id,sizeof(char),4,fp);
        id[4]='\0';

        if(!strcmp(id,"RIFF")){
            fread(&size,sizeof(int16_t),2,fp);
            fread(id,sizeof(char),4,fp);
            id[4]='\0';

            if(!strcmp(id,"WAVE")){
                fread(id,sizeof(char),4,fp);
                fread(&format_length,sizeof(int16_t),2,fp);
                fread(&format_tag,sizeof(int16_t),1,fp);
                fread(&channels,sizeof(int16_t),1,fp);
                fread(&sample_rate,sizeof(int16_t),2,fp);
                fread(&avg_bytes_sec,sizeof(int16_t),2,fp);
                fread(&block_align,sizeof(int16_t),1,fp);
                fread(&bits_per_sample,sizeof(int16_t),2,fp);
                fread(id,sizeof(char),4,fp);
                fread(&data_size,sizeof(int16_t),2,fp);

                ret->size=data_size/sizeof(int16_t);
                // 动态分配了空间，记得要释放
                ret->data=(int16_t*)malloc(data_size);
                fread(ret->data,sizeof(int16_t),ret->size,fp);
            }
            else{
                cout<<"Error: RIFF File but not a wave file\n";
            }
        }
        else{
            cout<<"ERROR: not a RIFF file\n";
        }
    }
    fclose(fp);
}

void freeSource(WavData* data){
    free(data->data);
}

void calEnergy(int *e_list,WavData *wave_data,int len){
    int n_len=len/256;
//    int e_list[n_len];
    int *p;
    p=e_list;


    int sum = 0;
    for (int i=0;i<len;i++){
        sum = sum + wave_data->data[i] * wave_data->data[i];
        if((i + 1) % 20 == 0){

            *p=sum;
            p++;
            sum = 0;
        }
        else if(i == len - 1){
            *p=sum;

        }


    }

//    for i in range(len(wave_data)) :
//    sum = sum + (int(wave_data[i]) * int(wave_data[i]))
//    if (i + 1) % 256 == 0 :
//    energy.append(sum)
//    sum = 0
//    elif i == len(wave_data) - 1 :
//    energy.append(sum)


}

int main(){
    WavData song;
    ofstream out("city_16k.txt");
    const char* fname="city_16k.wav";
    loadWavFile(fname,&song);
    cout<<song.size<<"\n"<<song.data[0]<<endl;


    int n_len=song.size/20;
    int e_list[n_len];
    int len = song.size;

    calEnergy(e_list,&song,len);
    for(int f=0;f<n_len;f++){
        cout<<e_list[f]<<endl;

    }


    for(long i=0;i<song.size;i++){
        out<<song.data[i]<<',';
    }

    out.close();
    freeSource(&song);
    return 0;
}