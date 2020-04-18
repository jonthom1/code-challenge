package codechallenge.impl;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import codechallenge.interfaces.CmdHndlInterface;

public class Engine {

	private CmdParse cmdp;
	private Map<Integer, CmdHndlInterface> hndl_map;
	
	public Engine(CmdParse cmdp, Map<Integer, CmdHndlInterface> hndl_map) {
		super();
		this.cmdp = cmdp;
		this.hndl_map = hndl_map;
	}
	
	public List<String> process(final String input) {
		//Transform input command to command ID
		Command command = cmdp.parse(input);
		
		List<String> ret = new ArrayList<>();
		
		//Find command handle by ID and execute
		CmdHndlInterface hndl = hndl_map.getOrDefault(command.getCmd(), null);
		
		if(hndl != null) { ret = hndl.handle(command); }
		
		return ret;
	}
}
