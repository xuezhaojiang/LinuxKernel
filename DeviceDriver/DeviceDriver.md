这个也是博大精深，请仔细阅读下面两个链接。  
1.[Writing device drivers in Linux: A brief tutorial](http://freesoftwaremagazine.com/articles/drivers_linux/)  
2.[统一设备模型](http://www.wowotech.net/sort/device_model/page/2)  
  
### 关键数据结构  
#### kobject  
核心字段：name,kref,dentry.  
kobject的设计初衷就是引用计数，管理device、device_driver这些结构的引用计数，便于内存决定是否释放这些结构。后来kobject又和sysfs文件结构结合了起来。每一个Kobject，都会对应sysfs中的一个目录。attribute，在sysfs文件系统中是以文件的形式提供的，即：kobject的所有属性，都在它对应的sysfs目录下以文件的形式呈现。[2(4)]  
kobject是面向对象的思想在Linux kernel中的体现。好好体会其中组合的使用。  
设计模式中有关于复用时组合和继承的使用描述，当使用继承的时候，肯定是需要利用多态的特性。如果用不到多态的特性，继承的关系是无用的。继承关系的耦合度很高，一处改会导致处处需要修改。组合的耦合相对较小。参考了知乎问题[开发中为什么要多用组合少用继承](https://www.zhihu.com/question/49008835/answer/113876529)中NickZhang的回答。  
#### ktype  
#### device  
核心字段：kobj,device_driver,power,release().  
可以看出是和电源管理相关的。  
#### device_driver  
核心字段：name,kobj,devices,probe(),remove(),shutdown(),suspend(),resume().  
和电源、热拔插相关。  
用Device（struct device）和Device Driver（struct device_driver）两个数据结构，分别从“有什么用”和“怎么用”两个角度描述硬件设备。[2(1)]  
#### cdev  
核心字段：kobj,file_operation,dev_t。  
和文件操作有关，[Writing device drivers in Linux: A brief tutorial](http://freesoftwaremagazine.com/articles/drivers_linux/)中的例子memory driver注册的也是cdev和file_operation。  
cdev时VFS层的抽象，device,device_driver是设备驱动模型的抽象。  
#### block_device  
核心字段：dev_t,inode,bd_openers.  
  
#### 设备资源  
供电、时钟、内存、GPIO、中断、DMA、虚拟地址空间等。[2(9)]  
  