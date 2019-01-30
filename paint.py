import numpy as np
import pylab as pl
times=np.arange(3,6,0.01)  #times为x的值，0为起点，5为终点，0,01为步长
fun=lambda x:(x-5.4)**2+24.24#np.cos(20*x)*np.exp(-pl.absolute(x))   #fun为关于x的函数，也就是对应于x的y的值

pl.plot(times,fun(times))  #画图
pl.xlabel("time period length")  #x轴的标记
pl.ylabel("evacuation time")  #y轴的标记
#pl.title("damped oscillation")  #图的标题
pl.show()   #显示图
