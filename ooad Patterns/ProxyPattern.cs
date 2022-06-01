//In proxy(in place of) pattern, one class represents the functionality of another class to aviod data loadence.
//interface is implemeted by both the real class and its proxy class.
//proxy class has reference of real class.
//In main we create proxy class object. 
//in proxy class we create instance of real class and calling the function of real class in its proxy class.
//we me made our proxy composed of the real class object (composition).
/*
The Proxy pattern uses a proxy (surrogate) object “in place of” another object.
The objective of a proxy object is to control the creation of and access to the real object it represents.
A common use of a proxy is to defer the cost of instantiating of an object
virtual proxy creates expensive objects on demand.


-----------------VISIT IT >>>>>>>>>>> https://springframework.guru/gang-of-four-design-patterns/proxy-pattern/
*/


how proxy is beneficial???
    When you 
using System;

namespace ProxyPattern
{

    class Program
    {
        //interface - subject
        public interface Image
        {
            void display();
        }
        
        //real class - real subjects implementing interface
        public class RealImage : Image
        {

        private String fileName;

        
        public RealImage(String fileName)
        {
            this.fileName = fileName;
            loadFromDisk(fileName);
        }
        public void display()
        {
            Console.WriteLine("Displaying " + fileName);
        }

        private void loadFromDisk(String fileName)
        {
            Console.WriteLine("Loading " + fileName);
        }
    }

        //proxy class having referece of real class
        public class ProxyImage : Image
        {

        private RealImage realImage;             //instnace for real class
        private String fileName;

        public ProxyImage(String fileName)
        {
            this.fileName = fileName;
        }

        public void display()
        {
            if (realImage == null)
            {
                realImage = new RealImage(fileName);
            }
            realImage.display();                //Through proxy class, we are calling the method of real class.
        }
    }
    static void Main(string[] args)
        {
        //why proxyImage attribute? Actually by help of proxy class, we are creating object of real class which loads data for us, once.
        //
            Image image = new ProxyImage("test_10mb.jpg");

            //image will be loaded from disk
            image.display();
          

            //image will not be loaded from disk
            image.display();
        }
    }
}
