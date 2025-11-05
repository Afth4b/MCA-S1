#private attributes and overloading

class time:
    def __init__(self,hour,minute,second):
        self._hour=hour
        self._minute=minute
        self._second=second

    def __add__(self,other):
        h=(self._hour+other._hour)%24
        m=self._minute+other._minute
        s=self._second+other._second
        if s>=60:
            s%=60
            m+=1
        if m>=60:
            m%=60
            h+=1
        return time(h,m,s)
    
    def __str__(self):
        return f"{self._hour:02d}:{self._minute:02d}:{self._second:02d}"

t1=time(12,61,30)
t2=time(16,50,47)
t=t1+t2
print(t)