package codechallenge.impl;

import java.util.HashMap;
import java.util.Map;

import codechallenge.impl.cmdhndl.FollowCmdHndl;
import codechallenge.impl.cmdhndl.PublishCmdHndl;
import codechallenge.impl.cmdhndl.TimelineCmdHndl;
import codechallenge.impl.cmdhndl.WallCmdHndl;
import codechallenge.interfaces.CmdHndlInterface;
import codechallenge.interfaces.DataInterface;
import codechallenge.interfaces.SubsInterface;

public class Logic {

	private Engine eng;
	private DataInterface data;
	private SubsInterface subs;
	
	public Logic() {
		super();
		
		//Data interface layer - shared
		this.data = new Data();
		this.subs = new Subs();
		
		//Build command dispatch table
		Map<Integer, CmdHndlInterface> hndl_map = new HashMap<>();
		hndl_map.put(Command.TIMELINE, new TimelineCmdHndl(data,subs));
		hndl_map.put(Command.PUBLISH, new PublishCmdHndl(data,subs));
		hndl_map.put(Command.FOLLOW, new FollowCmdHndl(data,subs));
		hndl_map.put(Command.WALL, new WallCmdHndl(data,subs));
		
		this.eng = new Engine(new CmdParse(), hndl_map);
	}


	public Engine engine() { return eng; }
}
