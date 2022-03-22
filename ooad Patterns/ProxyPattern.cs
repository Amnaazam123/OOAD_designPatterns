using System;

namespace ProxyPattern
{

    class Program
    {
        public interface Image
        {
            void display();
        }
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

        public class ProxyImage : Image
        {

        private RealImage realImage;
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
            realImage.display();
        }
    }
    static void Main(string[] args)
        {
            Image image = new ProxyImage("test_10mb.jpg");

            //image will be loaded from disk
            image.display();
          

            //image will not be loaded from disk
            image.display();
        }
    }
}
