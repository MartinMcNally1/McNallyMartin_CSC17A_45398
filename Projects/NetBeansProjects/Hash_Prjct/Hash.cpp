#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>


using namespace std;

//Prototype functions
unsigned int RSHash(const string&);     //Hash Function from RS
unsigned int JSHash(const string&);     //Hash Function from JS
unsigned int PJWHash(const string&);    //Hash Function from PJW
unsigned int ELFHash(const string&);    //Hash Function from ELF
unsigned int BKDRHash(const string&);   //Hash Function from BKDR
unsigned int SDBMHash(const string&);   //Hash Function from SDBM
unsigned int DJBHash(const string&);    //Hash Function from DLB
unsigned int DEKHash(const string&);    //Hash Function from DEK
unsigned int BPHash(const string&);     //Hash Function from BP
unsigned int FNVHash(const string&);    //Hash Function from FNV
unsigned int APHash(const string&);     //Hash Function from AP

//Main
int main ( int argc, char** argv )
{
    //Quote Variable
    string key = "Then out spake brave Horatius,\n"
                 "The Captain of the Gate\n"
                 "To every man upon this earth\n"
                 "Death cometh soon or late.\n"
                 "And how can man die better\n"
                 "Than facing fearful odds,\n"
                 "For the ashes of his fathers,\n"
                 "And the temples of his gods.\n";
            
    cout << "Hash number from RS function: " << RSHash(key) << endl;
    cout << "Hash number from JS function: " << JSHash(key) << endl;
    cout << "Hash number from PJW function: " << PJWHash(key) << endl;
    cout << "Hash number from ELF function: " << ELFHash(key) << endl;
    cout << "Hash number from BKDR function: " << BKDRHash(key) << endl;
    cout << "Hash number from SDBM function: " << SDBMHash(key) << endl;
    cout << "Hash number from DJB function: " << DJBHash(key) << endl;
    cout << "Hash number from DEK function: " << DEKHash(key) << endl;
    cout << "Hash number from BP function: " << BPHash(key) << endl;
    cout << "Hash number from FNV function: " << FNVHash(key) << endl;
    cout << "Hash number from AP function: " << APHash(key) << endl;
    
    return 0;
}

unsigned int RSHash(const string& str)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash * a + str[i];
      a    = a * b;
   }

   return hash;
}
/* End Of RS Hash Function */


unsigned int JSHash(const string&str)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}
/* End Of JS Hash Function */


unsigned int PJWHash(const string&str)
{
   unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << OneEighth) + str[i];

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}
/* End Of  P. J. Weinberger Hash Function */


unsigned int ELFHash(const string&str)
{
   unsigned int hash = 0;
   unsigned int x    = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << 4) + str[i];
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
   }

   return hash;
}
/* End Of ELF Hash Function */


unsigned int BKDRHash(const string&str)
{
   unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash * seed) + str[i];
   }

   return hash;
}
/* End Of BKDR Hash Function */


unsigned int SDBMHash(const string&str)
{
   unsigned int hash = 0;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = str[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}
/* End Of SDBM Hash Function */


unsigned int DJBHash(const string&str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash;
}
/* End Of DJB Hash Function */


unsigned int DEKHash(const string&str)
{
   unsigned int hash = static_cast<unsigned int>(str.length());

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
   }

   return hash;
}
/* End Of DEK Hash Function */


unsigned int BPHash(const string&str)
{
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = hash << 7 ^ str[i];
   }

   return hash;
}
/* End Of BP Hash Function */


unsigned int FNVHash(const string&str)
{
   const unsigned int fnv_prime = 0x811C9DC5;
   unsigned int hash = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash *= fnv_prime;
      hash ^= str[i];
   }

   return hash;
}
/* End Of FNV Hash Function */


unsigned int APHash(const string&str)
{
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
                               (~((hash << 11) + (str[i] ^ (hash >> 5))));
   }

   return hash;
}
/* End Of AP Hash Function */
