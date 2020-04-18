package codechallenge.impl;

import java.util.HashMap;
import java.util.Map;

public class CmdParse {
	private Map<String, Integer> cmdmap;
	
	public CmdParse() {
		cmdmap = new HashMap<>();
		
		cmdmap.put("->", Command.PUBLISH);
		cmdmap.put("", Command.TIMELINE);
		cmdmap.put("follow", Command.FOLLOW);
		cmdmap.put("wall", Command.WALL);
	}
	
	public Command parse(final String input) {
		String[] split = input.split(" ",3);
		
		Command ret = new Command(
				cmdmap.getOrDefault( split.length > 1 ? split[1] : "" , -1)
				, split.length > 0 ? split[0] : ""
				, split.length > 2 ? split[2] : ""
				);
		
		return ret;
	}
	
	
}
