package codechallenge.interfaces;

import java.util.List;

import codechallenge.impl.Command;

public abstract class CmdHndlInterface {

	protected DataInterface data;
	protected SubsInterface subs;
	
	public CmdHndlInterface(DataInterface data, SubsInterface subs) {
		super();
		this.data = data;
		this.subs = subs;
	}

	abstract public List<String> handle(final Command command);
}
