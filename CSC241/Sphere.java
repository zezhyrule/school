public class Sphere {
  private double theRadius;
  
  public Sphere() {
  // Default constructor: Creates a sphere and
  // initializes its radius to a default value.
  // Precondition: None.
  // Postcondition: A sphere of radius 1 exists.
    setRadius (1.0);
  } // end default constructor

  public Sphere(double initialRadius) {
  // Constructor: Creates a sphere and initializes 
  // its radius.
  // Precondition: initialRadius is the desired radius.
  // Postcondition: A sphere of radius initialRadius
  // exists.
    setRadius (initialRadius);
  } // end constructor

  public void setRadius(double newRadius) {
  // Sets (alters) the radius of an existing sphere.
  // Precondition: newRadius is the desired radius.
  // Postcondition: The sphere's radius is newRadius.
    if (newRadius >= 0.0) {
      theRadius = newRadius;
    }  // end if
  } // end setRadius

  public double radius() {
  // Determines a sphere's radius.
  // Precondition: None.
  // Postcondition: Returns the radius.
    return theRadius;
  } // end radius
  
  public double diameter() {
  // Determines a sphere's diameter.
  // Precondition: None.
  // Postcondition: Returns the diameter.
    return 2.0 * theRadius;
  } // end diameter
  
  public double circumference() {
  // Determines a sphere's circumference.
  // Precondition: None.
  // Postcondition: Returns the circumference.
    return Math.PI * diameter();
  } // end circumference
  
  public double area() {
  // Determines a sphere's surface area.
  // Precondition: None.
  // Postcondition: Returns the surface area.
    return 4.0 * Math.PI * theRadius * theRadius;
  } // end area
  
  public double volume() {
  // Determines a sphere's volume.
  // Precondition: None.
  // Postcondition: Returns the volume.
    return (4.0*Math.PI * Math.pow(theRadius, 3.0)) / 3.0;
  } // end volume

  public void displayStatistics() {  
  // Displays statistics of a sphere.
  // Precondition: Assumes System.out is available.
  // Postcondition: None.
    System.out.println("\nRadius = " + radius() +
                 "\nDiameter = " + diameter() +
                 "\nCircumference = " + circumference() +
                 "\nArea = " + area() +
                 "\nVolume = " + volume());
  }  // end displayStatistics
} // end Sphere
