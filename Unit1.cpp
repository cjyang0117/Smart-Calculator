//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool operand(String d){
  if(d=="+"||d=="-"||d=="*"||d=="/"||d=="("||d==")"){
    return 0;
  }
}
int priority(String d,bool c){
  if(d=="+"||d=="-"){
    return 1;
  }else if(d=="*"||d=="/"){
    return 2;
  }else if(d=="("&&c){
    return 3;
  }else{
    return 0;
  }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
  int c=0;
  bool first=1;
  String *data;
  String Data=Lab->Caption;
  data=new String[Data.Length()];
  for(int i=0;i<Data.Length();i++){
    if(operand(Data.SubString(i+1,1))){
      if(first) first=0;
      data[c]+=Data.SubString(i+1,1);
    }else{
      if(first){
        first=0;
        data[c++]=Data.SubString(i+1,1);
      }else{
        if(operand(Data.SubString(i,1))) c++;
        data[c]=Data.SubString(i+1,1);
        c++;
      }
    }
  }
  if(!(operand(Data.SubString(Data.Length(),1)))) c--;

  String stack[10];
  bool in=1;
  int top=-1,c1=0;
  String *post;
  post=new String[c+1];
  for(int i=0;i<=c;i++){
    if(data[i]==")"){
      for(int j=top;;j--){
        if(stack[j]!="("){
          post[c1++]=stack[top--];
        }else{
          top--;
          break;
        }
      }
      in=1;
    }else{
      if(operand(data[i])){
        post[c1++]=data[i];
      }else{
        if(top>=0&&priority(stack[top],in)>=priority(data[i],in)){
          for(int j=top;j>-1;j--){
            if(top>=0&&priority(stack[j],in)>=priority(data[i],in)){
              post[c1++]=stack[top--];
            }else{
              break;
            }
          }
          stack[++top]=data[i];
        }else{
          stack[++top]=data[i];
          if(data[i]=="(") in=0;
        }
      }
    }
  }
  for(int i=top;i>-1;i--){
    post[c1++]=stack[i];
  }
  c1=0;
  top=-1;

  double sum;
  for(int i=0;i<=c;i++){
    if(operand(post[i])){
      stack[++top]=post[i];
    }else{
      if(post[i]=="+"){
        sum=stack[top-1].ToDouble()+stack[top].ToDouble();
        stack[--top]=sum;
      }else if(post[i]=="-"){
        sum=stack[top-1].ToDouble()-stack[top].ToDouble();
        stack[--top]=sum;
      }else if(post[i]=="*"){
        sum=stack[top-1].ToDouble()*stack[top].ToDouble();
        stack[--top]=sum;
      }else{
        sum=stack[top-1].ToDouble()/stack[top].ToDouble();
        stack[--top]=sum;
      }
    }
  }
  ShowMessage(stack[0]);

  delete[] data;
  delete[] post;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
  Lab->Caption="";         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"1";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"0";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"2";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"3";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"4";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"5";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"6";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"7";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"8";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"9";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"+";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"-";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"*";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"/";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+".";        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+"(";            
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
  Lab->Caption=Lab->Caption+")";            
}
//---------------------------------------------------------------------------

