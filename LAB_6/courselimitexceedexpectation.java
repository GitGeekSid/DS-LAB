import java.util.Scanner;
 class student{
     String name;
     int coursecount;
     final static int max=3;
     student(String name,int coursecount)
     {
         super();
         this.name=name;
         this.coursecount=coursecount;
     }
    public String tostring()
    {
        return "student"+coursecount;
    }
    public void display(student obj)
    {
        System.out.println("Name is: "+name);
        System.out.println("Course Count: "+coursecount);
    }
 }
    class courselimitexceedexpectation{
    public void enrollcourse(student obj) throws courselimitexceedexpectation
    {
        if(coursecount > max)
        {
            throw new courselimitexceedexpectation(coursecount);
        }
        else{
            System.out.println("Allowed for enrollment");
        }
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int numstu=sc.nextInt();
        student[] obj=new student[numstu];
        for(int i=0;i<numstu;i++)
        {
            System.out.println("Enter the name: ");
            String name=sc.nextLine();
            System.out.println("Enter the coursecount: ");
            int coursecount=sc.nextInt();
            obj[i]=new student(name,coursecount);
            try{
                obj[i].enrollcourse(obj[i]);
            }
            catch(courselimitexceedexpectation e){
                System.out.println("Caught: "+e);
            }
          if(coursecount<=max)
            {
             obj[i].display(obj[i]);
            }
        }
    }
}