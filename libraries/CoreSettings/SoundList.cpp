#include "SoundList.h"

SoundList::SoundList()
{
}

String SoundList::getRandom()
{ return sounds[random(0,count-1)];
}

String SoundList::getCSV()
{
  String s="";
  for(int i=0; i<count; i++)
  { if(i!=0)
    { s=s+",";
    }
    s = s + sounds[i];
  }
  return s;
}

void SoundList::setCSV(String csv)
{ 
  String data=csv;
  int commas = 1; //no commas mean 1 data item
  for (unsigned int i = 0; i < data.length(); i++)
    if (data[i] == ',') commas++;

   
  count=commas;
  for (int i = 0; i < count; i++)
  { int pos = data.indexOf(',');
    if(pos>0)
    { sounds[i] = data.substring(0, pos).replace("\"","").trim(); //removing quotes and surrounding spaces
      data = data.substring(pos + 1);
    } else
    { //last item
      sounds[i]=data.replace("\"","").trim();
      data="";
    }
  }
}