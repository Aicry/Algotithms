 bool detectCapitalUse(string word) {

         int n=word.size();
         if(n==1)return true;
         if(word[0]>='a'&&word[0]<='z')
          {
             
              for(int i=1;i<n;++i)
                  if(word[i]<'a')
                      return false;
              return true;
          }

        if(word[0]>='A'&&word[0]<='Z')
          {          
                 if(word[1]>='a'&&word[1]<='z')
                 {

                  for(int i=2;i<n;++i)
                  if(word[i]<'a')
                      return false;
                  return true;
                 }
          

               if(word[1]>='A'&&word[1]<='Z'){
                   for(int i=2;i<n;++i)
                   if(word[i]>'Z')
                      return false;
                  return true;
               }


        }
        return true;
 } 

  bool detectCapitalUse(string word) {
        int mount = 0;
        int n=word.size();
        for (int i = 0; i < n; ++i) {
            if (isupper(word[i]) && mount++ < i) {
                return false;
            }
        }
        
        return mount == n || mount <= 1;
    }