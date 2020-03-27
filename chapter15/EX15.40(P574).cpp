/*
Nothing special will happen. The codes as following:
std::shared_ptr<std::set<line_no>> ret_lines =
       std::make_shared<std::set<line_no>>(left.begin(), left.end());
Since std::make_shared will allocate dynamically a new std::set, nothing will be added into this std::set if any set is empty.
*/