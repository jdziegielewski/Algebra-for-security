/**
 * 
 */

/**
 * @author 20181064
 *
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.lang.*;



public class input1 {

	public static void main(String[] args) throws FileNotFoundException {
	displaypolynomial displayObject = new displaypolynomial();
	displaypolylongdiv displaylongdivObject = new displaypolylongdiv();
	displaypolyeqpoly displaypolyeqpolyObject = new displaypolyeqpoly();
	convertpolynomial convertpolyObject = new convertpolynomial();
	convertpolymodpoly convertpolymodpolyObject = new convertpolymodpoly();
	polynomialaddition addpolyObject = new polynomialaddition();
	polynomialsubtraction subpolyObject = new polynomialsubtraction();
	longdivision longdivisObject = new longdivision();
	polyequalspoly polyeqpolyObject = new polyequalspoly();
	//polynomialmultiplication polymultiObject = new polynomialmultiplication();
	



	File file = new File("example.txt");
	Scanner scan = new Scanner(file);
	String line;
	int mod=0;
	int switch1=0;
	String f=" ",g=" ",h=" ";
	int deg;
	while(scan.hasNextLine()) {
	line=scan.nextLine();
	while(line.length()!=0 && line.charAt(0) != '#') {
	
	StringTokenizer str = new StringTokenizer(line);
	String firsttoken = str.nextToken();
	
	if(firsttoken.equals("[mod]")) {
			mod=Integer.parseInt(str.nextToken());
			System.out.println("mod " +  mod);
			
	}
	
	else if(firsttoken.equals("[display-poly]")) {
		switch1=1;
		System.out.println("display");
		
	}
	
	 else if(firsttoken.equals("[add-poly]")) {
		switch1=2;
		System.out.println("add");
		
	}
	
	 else if(firsttoken.equals("[subtract-poly]")) {
		switch1=3;
		System.out.println("sub");
		
	}
	
	 else if(firsttoken.equals("[multiply-poly]")) {
		switch1=4;
		System.out.println("multi");
		
	}
	
	 else if(firsttoken.equals("[long-div-poly]")) {
		switch1=5;
		System.out.println("long-div");
		
	}
	
	 else if(firsttoken.equals("[euclid-poly]")) {
		switch1=6;
		System.out.println("euclid");
		
	}
	
	 else if(firsttoken.equals("[equals-poly-mod]")) {
		switch1=7;
		System.out.println("equal pol");
		
	}
	
	 else if(firsttoken.equals("[irreducible]")) {
		switch1=8;
		System.out.println("irr");
		
	}
	
	 else if(firsttoken.equals("[find-irred]")) {
		switch1=9;
		System.out.println("finirr");
		
	}
	
	 else if(firsttoken.equals("[f]")) {
		f=str.nextToken();
		System.out.println(f);
		
		
	}
	 else if(firsttoken.equals("[g]")) {
		g=str.nextToken();
		System.out.println(g);
		
	}
	 else if(firsttoken.equals("[h]")) {
		h=str.nextToken();
		System.out.println(h);
		
	}
	 else if(firsttoken.equals("[deg]")) {
		 	deg=Integer.parseInt(str.nextToken());
			System.out.println(deg);
			
		}
	
		if(firsttoken.equals("[answer]") || firsttoken.equals("[answ-q]")
			|| firsttoken.equals("[answ-r]") || firsttoken.equals("[answ-a]")
			|| firsttoken.equals("[answ-b]") || firsttoken.equals("[answ-d]") ) {
			
		}
		if(scan.hasNextLine()) {
		line=scan.nextLine();
		}
	}
	//end inner loop
	//calculations 
	//switch case
	switch(switch1) {
	  case 1://[display-poly]
	    //function should be here ( not the code ) (put the funtions in different classes so it wont be messy)
		  displayObject.displaypoly(convertpolyObject.polyconversion(f,mod));
		  break;
	  case 2://[add-poly]
		//function should be here
		  displayObject.displaypoly(addpolyObject.polyaddition(convertpolyObject.polyconversion(f,mod),convertpolyObject.polyconversion(g,mod),mod));
	    break;
	  case 3://[subtract-poly]
		//function should be here
		  displayObject.displaypoly(subpolyObject.polysubtraction(convertpolyObject.polyconversion(f,mod),convertpolyObject.polyconversion(g,mod),mod));
		break;
	  case 4://[multiply-poly]
		//displayObject.displaypoly(polymultiObject.polymultiplication(convertpolyObject.polyconversion(f,mod),convertpolyObject.polyconversion(g,mod),mod));
		break;
	  case 5://[long-div-poly]
		  displaylongdivObject.displaypolyld(longdivisObject.longdiv(convertpolyObject.polyconversion(f,mod),convertpolyObject.polyconversion(g,mod),mod));
		break;
	  case 6://[euclid-poly]
		//function should be here
		break;
	  case 7://[equals-poly-mod]
		displaypolyeqpolyObject.displaypeqp(polyeqpolyObject.peqp(convertpolyObject.polyconversion(f,mod),convertpolyObject.polyconversion(g,mod),convertpolyObject.polyconversion(h,mod),mod));
		break;
	  case 8://[irreducible]
		//function should be here
		break;
	  case 9://[find-irred]
		//function should be here 
		break;		
	}

	}//end outerloop

	
	
	
	}}

