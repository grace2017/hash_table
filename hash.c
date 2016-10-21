inline unsigned time33(char const*str, int len) 
{ 
     unsigned long hash = 5381; 
     /* variant with the hash unrolled eight times */ 
     for (; len >= 8; len -= 8) { 
         hash = ((hash << 5) + hash) + *str++; 
         hash = ((hash << 5) + hash) + *str++; 
         hash = ((hash << 5) + hash) + *str++; 
         hash = ((hash << 5) + hash) + *str++; 
        hash = ((hash << 5) + hash) + *str++; 
        hash = ((hash << 5) + hash) + *str++; 
        hash = ((hash << 5) + hash) + *str++; 
        hash = ((hash << 5) + hash) + *str++; 
    } 
    switch (len) { 
        case 7: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */ 
        case 6: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */ 
        case 5: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */ 
        case 4: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */ 
        case 3: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */ 
        case 2: hash = ((hash << 5) + hash) + *str++; /* fallthrough... */ 
        case 1: hash = ((hash << 5) + hash) + *str++; break; 
        case 0: break; 
    } 
    return hash; 
} 

