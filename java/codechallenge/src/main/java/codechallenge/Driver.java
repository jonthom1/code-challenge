package codechallenge;

import java.util.List;
import java.util.Scanner;

import codechallenge.impl.Logic;

public class Driver {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("> ");
		String input = in.nextLine();
		
		Logic logic = new Logic();
		
		while(!input.equals("exit")) {
			List<String> ret = logic.engine().process(input);
			
			ret.forEach(s -> {
				System.out.println(s);
			});
			
			System.out.print("> ");
			input = in.nextLine();
		}

		in.close();
	}

}
