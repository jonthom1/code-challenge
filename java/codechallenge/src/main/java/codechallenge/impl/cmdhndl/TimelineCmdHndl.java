package codechallenge.impl.cmdhndl;

import java.util.Date;
import java.util.List;

import codechallenge.impl.Command;
import codechallenge.impl.Entry;
import codechallenge.impl.UtilFunc;
import codechallenge.interfaces.CmdHndlInterface;
import codechallenge.interfaces.DataInterface;
import codechallenge.interfaces.SubsInterface;

public class TimelineCmdHndl extends CmdHndlInterface {

	public TimelineCmdHndl(DataInterface data, SubsInterface subs) {
		super(data, subs);
	}

	@Override
	public List<String> handle(Command command) {
		List<Entry> entries = data.timeline(command.getUser());
		
		UtilFunc util = new UtilFunc();
		
		util.formatTimeDiff(entries, new Date());
		
		return util.formatEntries(entries);
	}

}
