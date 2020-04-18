package codechallenge.impl.cmdhndl;

import java.util.ArrayList;
import java.util.List;

import codechallenge.impl.Command;
import codechallenge.interfaces.CmdHndlInterface;
import codechallenge.interfaces.DataInterface;
import codechallenge.interfaces.SubsInterface;

public class FollowCmdHndl extends CmdHndlInterface {

	public FollowCmdHndl(DataInterface data, SubsInterface subs) {
		super(data, subs);
	}

	@Override
	public List<String> handle(Command command) {
		subs.follow(command.getUser(), command.getMessage());
		return new ArrayList<>();
	}

}
