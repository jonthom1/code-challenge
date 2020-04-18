package codechallenge.impl.cmdhndl;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import codechallenge.impl.Command;
import codechallenge.interfaces.CmdHndlInterface;
import codechallenge.interfaces.DataInterface;
import codechallenge.interfaces.SubsInterface;

public class PublishCmdHndl extends CmdHndlInterface {

	public PublishCmdHndl(DataInterface data, SubsInterface subs) {
		super(data, subs);
	}

	@Override
	public List<String> handle(Command command) {
		data.publish(command.getUser(), command.getMessage(), new Date());
		return new ArrayList<String>();
	}

}
