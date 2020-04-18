package codechallenge.impl.cmdhndl;

import java.util.Date;
import java.util.List;
import java.util.Set;

import codechallenge.impl.Command;
import codechallenge.impl.Entry;
import codechallenge.impl.UtilFunc;
import codechallenge.interfaces.CmdHndlInterface;
import codechallenge.interfaces.DataInterface;
import codechallenge.interfaces.SubsInterface;

public class WallCmdHndl extends CmdHndlInterface {

	public WallCmdHndl(DataInterface data, SubsInterface subs) {
		super(data, subs);
	}

	@Override
	public List<String> handle(Command command) {
		Set<String> usubs = subs.followedBy(command.getUser());
		List<Entry> entries = data.timeline(usubs);
		
		UtilFunc util = new UtilFunc();
		
		util.formatTimeDiff(entries, new Date());
		return util.formatEntriesWithUser(entries);
	}

}
