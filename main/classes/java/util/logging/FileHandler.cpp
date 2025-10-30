#include <java/util/logging/FileHandler.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/SecurityException.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/FileLock.h>
#include <java/nio/channels/OverlappingFileLockException.h>
#include <java/nio/file/AccessDeniedException.h>
#include <java/nio/file/FileAlreadyExistsException.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/NoSuchFileException.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractSet.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <java/util/logging/ErrorManager.h>
#include <java/util/logging/FileHandler$1.h>
#include <java/util/logging/FileHandler$InitializationErrorManager.h>
#include <java/util/logging/FileHandler$MeteredStream.h>
#include <java/util/logging/Filter.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/StreamHandler.h>
#include <java/util/logging/XMLFormatter.h>
#include <jdk/internal/misc/VM.h>
#include <jcpp.h>

#undef ALL
#undef APPEND
#undef CREATE_NEW
#undef MAX_LOCKS
#undef NOFOLLOW_LINKS
#undef OFF
#undef OPEN_FAILURE
#undef WRITE

using $FileArray = $Array<::java::io::File>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $FileChannel = ::java::nio::channels::FileChannel;
using $FileLock = ::java::nio::channels::FileLock;
using $OverlappingFileLockException = ::java::nio::channels::OverlappingFileLockException;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $AccessDeniedException = ::java::nio::file::AccessDeniedException;
using $FileAlreadyExistsException = ::java::nio::file::FileAlreadyExistsException;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $NoSuchFileException = ::java::nio::file::NoSuchFileException;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractSet = ::java::util::AbstractSet;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;
using $ErrorManager = ::java::util::logging::ErrorManager;
using $FileHandler$1 = ::java::util::logging::FileHandler$1;
using $FileHandler$InitializationErrorManager = ::java::util::logging::FileHandler$InitializationErrorManager;
using $FileHandler$MeteredStream = ::java::util::logging::FileHandler$MeteredStream;
using $Filter = ::java::util::logging::Filter;
using $Formatter = ::java::util::logging::Formatter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;
using $StreamHandler = ::java::util::logging::StreamHandler;
using $XMLFormatter = ::java::util::logging::XMLFormatter;
using $VM = ::jdk::internal::misc::VM;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _FileHandler_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(FileHandler, $assertionsDisabled)},
	{"meter", "Ljava/util/logging/FileHandler$MeteredStream;", nullptr, $PRIVATE, $field(FileHandler, meter)},
	{"append", "Z", nullptr, $PRIVATE, $field(FileHandler, append)},
	{"limit", "J", nullptr, $PRIVATE, $field(FileHandler, limit)},
	{"count", "I", nullptr, $PRIVATE, $field(FileHandler, count)},
	{"pattern", "Ljava/lang/String;", nullptr, $PRIVATE, $field(FileHandler, pattern)},
	{"lockFileName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(FileHandler, lockFileName)},
	{"lockFileChannel", "Ljava/nio/channels/FileChannel;", nullptr, $PRIVATE, $field(FileHandler, lockFileChannel)},
	{"files", "[Ljava/io/File;", nullptr, $PRIVATE, $field(FileHandler, files)},
	{"MAX_LOCKS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(FileHandler, MAX_LOCKS)},
	{"maxLocks", "I", nullptr, $PRIVATE, $field(FileHandler, maxLocks)},
	{"locks", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(FileHandler, locks)},
	{}
};

$MethodInfo _FileHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(FileHandler::*)()>(&FileHandler::init$)), "java.io.IOException,java.lang.SecurityException"},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(FileHandler::*)($String*)>(&FileHandler::init$)), "java.io.IOException,java.lang.SecurityException"},
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, $method(static_cast<void(FileHandler::*)($String*,bool)>(&FileHandler::init$)), "java.io.IOException,java.lang.SecurityException"},
	{"<init>", "(Ljava/lang/String;II)V", nullptr, $PUBLIC, $method(static_cast<void(FileHandler::*)($String*,int32_t,int32_t)>(&FileHandler::init$)), "java.io.IOException,java.lang.SecurityException"},
	{"<init>", "(Ljava/lang/String;IIZ)V", nullptr, $PUBLIC, $method(static_cast<void(FileHandler::*)($String*,int32_t,int32_t,bool)>(&FileHandler::init$)), "java.io.IOException,java.lang.SecurityException"},
	{"<init>", "(Ljava/lang/String;JIZ)V", nullptr, $PUBLIC, $method(static_cast<void(FileHandler::*)($String*,int64_t,int32_t,bool)>(&FileHandler::init$)), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{"configure", "()V", nullptr, $PRIVATE, $method(static_cast<void(FileHandler::*)()>(&FileHandler::configure))},
	{"generate", "(Ljava/lang/String;II)Ljava/io/File;", nullptr, $PRIVATE, $method(static_cast<$File*(FileHandler::*)($String*,int32_t,int32_t)>(&FileHandler::generate)), "java.io.IOException"},
	{"generate", "(Ljava/lang/String;III)Ljava/io/File;", nullptr, $STATIC, $method(static_cast<$File*(*)($String*,int32_t,int32_t,int32_t)>(&FileHandler::generate)), "java.io.IOException"},
	{"isParentWritable", "(Ljava/nio/file/Path;)Z", nullptr, $PRIVATE, $method(static_cast<bool(FileHandler::*)($Path*)>(&FileHandler::isParentWritable))},
	{"open", "(Ljava/io/File;Z)V", nullptr, $PRIVATE, $method(static_cast<void(FileHandler::*)($File*,bool)>(&FileHandler::open)), "java.io.IOException"},
	{"openFiles", "()V", nullptr, $PRIVATE, $method(static_cast<void(FileHandler::*)()>(&FileHandler::openFiles)), "java.io.IOException"},
	{"publish", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"rotate", "()V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(FileHandler::*)()>(&FileHandler::rotate))},
	{}
};

$InnerClassInfo _FileHandler_InnerClassesInfo_[] = {
	{"java.util.logging.FileHandler$InitializationErrorManager", "java.util.logging.FileHandler", "InitializationErrorManager", $PRIVATE | $STATIC},
	{"java.util.logging.FileHandler$MeteredStream", "java.util.logging.FileHandler", "MeteredStream", $PRIVATE | $STATIC | $FINAL},
	{"java.util.logging.FileHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.FileHandler",
	"java.util.logging.StreamHandler",
	nullptr,
	_FileHandler_FieldInfo_,
	_FileHandler_MethodInfo_,
	nullptr,
	nullptr,
	_FileHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.FileHandler$InitializationErrorManager,java.util.logging.FileHandler$MeteredStream,java.util.logging.FileHandler$1"
};

$Object* allocate$FileHandler($Class* clazz) {
	return $of($alloc(FileHandler));
}

bool FileHandler::$assertionsDisabled = false;
$Set* FileHandler::locks = nullptr;

void FileHandler::open($File* fname, bool append) {
	$useLocalCurrentObjectStackCache();
	int64_t len = 0;
	if (append) {
		len = $nc(fname)->length();
	}
	$var($FileOutputStream, fout, $new($FileOutputStream, $($nc(fname)->toString()), append));
	$var($BufferedOutputStream, bout, $new($BufferedOutputStream, fout));
	$set(this, meter, $new($FileHandler$MeteredStream, bout, len));
	setOutputStream(this->meter);
}

void FileHandler::configure() {
	$useLocalCurrentObjectStackCache();
	$var($LogManager, manager, $LogManager::getLogManager());
	$var($String, cname, $of(this)->getClass()->getName());
	$set(this, pattern, $nc(manager)->getStringProperty($$str({cname, ".pattern"_s}), "%h/java%u.log"_s));
	this->limit = manager->getLongProperty($$str({cname, ".limit"_s}), 0);
	if (this->limit < 0) {
		this->limit = 0;
	}
	this->count = manager->getIntProperty($$str({cname, ".count"_s}), 1);
	if (this->count <= 0) {
		this->count = 1;
	}
	this->append = manager->getBooleanProperty($$str({cname, ".append"_s}), false);
	$init($Level);
	setLevel($(manager->getLevelProperty($$str({cname, ".level"_s}), $Level::ALL)));
	setFilter($(manager->getFilterProperty($$str({cname, ".filter"_s}), nullptr)));
	setFormatter($(manager->getFormatterProperty($$str({cname, ".formatter"_s}), $$new($XMLFormatter))));
	this->maxLocks = manager->getIntProperty($$str({cname, ".maxLocks"_s}), FileHandler::MAX_LOCKS);
	if (this->maxLocks <= 0) {
		this->maxLocks = FileHandler::MAX_LOCKS;
	}
	try {
		setEncoding($(manager->getStringProperty($$str({cname, ".encoding"_s}), nullptr)));
	} catch ($Exception& ex) {
		try {
			setEncoding(nullptr);
		} catch ($Exception& ex2) {
		}
	}
}

void FileHandler::init$() {
	$StreamHandler::init$();
	this->maxLocks = FileHandler::MAX_LOCKS;
	checkPermission();
	configure();
	if ($nc(this->pattern)->isEmpty()) {
		$throwNew($NullPointerException);
	}
	openFiles();
}

void FileHandler::init$($String* pattern) {
	$StreamHandler::init$();
	this->maxLocks = FileHandler::MAX_LOCKS;
	if ($nc(pattern)->length() < 1) {
		$throwNew($IllegalArgumentException);
	}
	checkPermission();
	configure();
	$set(this, pattern, pattern);
	this->limit = 0;
	this->count = 1;
	openFiles();
}

void FileHandler::init$($String* pattern, bool append) {
	$StreamHandler::init$();
	this->maxLocks = FileHandler::MAX_LOCKS;
	if ($nc(pattern)->length() < 1) {
		$throwNew($IllegalArgumentException);
	}
	checkPermission();
	configure();
	$set(this, pattern, pattern);
	this->limit = 0;
	this->count = 1;
	this->append = append;
	openFiles();
}

void FileHandler::init$($String* pattern, int32_t limit, int32_t count) {
	$StreamHandler::init$();
	this->maxLocks = FileHandler::MAX_LOCKS;
	if (limit < 0 || count < 1 || $nc(pattern)->length() < 1) {
		$throwNew($IllegalArgumentException);
	}
	checkPermission();
	configure();
	$set(this, pattern, pattern);
	this->limit = limit;
	this->count = count;
	openFiles();
}

void FileHandler::init$($String* pattern, int32_t limit, int32_t count, bool append) {
	FileHandler::init$(pattern, (int64_t)limit, count, append);
}

void FileHandler::init$($String* pattern, int64_t limit, int32_t count, bool append) {
	$StreamHandler::init$();
	this->maxLocks = FileHandler::MAX_LOCKS;
	if (limit < 0 || count < 1 || $nc(pattern)->length() < 1) {
		$throwNew($IllegalArgumentException);
	}
	checkPermission();
	configure();
	$set(this, pattern, pattern);
	this->limit = limit;
	this->count = count;
	this->append = append;
	openFiles();
}

bool FileHandler::isParentWritable($Path* path) {
	$useLocalCurrentObjectStackCache();
	$var($Path, parent, $nc(path)->getParent());
	if (parent == nullptr) {
		$assign(parent, $nc($(path->toAbsolutePath()))->getParent());
	}
	return parent != nullptr && $Files::isWritable(parent);
}

void FileHandler::openFiles() {
	$useLocalCurrentObjectStackCache();
	$var($LogManager, manager, $LogManager::getLogManager());
	$nc(manager)->checkPermission();
	if (this->count < 1) {
		$throwNew($IllegalArgumentException, $$str({"file count = "_s, $$str(this->count)}));
	}
	if (this->limit < 0) {
		this->limit = 0;
	}
	if (!FileHandler::$assertionsDisabled && !(this->pattern != nullptr)) {
		$throwNew($AssertionError, $of("pattern should not be null"_s));
	}
	if (!FileHandler::$assertionsDisabled && ! !$nc(this->pattern)->isEmpty()) {
		$throwNew($AssertionError, $of("pattern should not be empty"_s));
	}
	$var($FileHandler$InitializationErrorManager, em, $new($FileHandler$InitializationErrorManager));
	setErrorManager(em);
	int32_t unique = -1;
	for (;;) {
		++unique;
		if (unique > this->maxLocks) {
			$throwNew($IOException, $$str({"Couldn\'t get lock for "_s, this->pattern}));
		}
		$set(this, lockFileName, $str({$($nc($(generate(this->pattern, 0, unique)))->toString()), ".lck"_s}));
		$synchronized(FileHandler::locks) {
			if ($nc(FileHandler::locks)->contains(this->lockFileName)) {
				continue;
			}
			$var($Path, lockFilePath, $Paths::get(this->lockFileName, $$new($StringArray, 0)));
			$var($FileChannel, channel, nullptr);
			int32_t retries = -1;
			bool fileCreated = false;
			while (channel == nullptr && retries++ < 1) {
				try {
					$init($StandardOpenOption);
					$assign(channel, $FileChannel::open(lockFilePath, $$new($OpenOptionArray, {
						static_cast<$OpenOption*>($StandardOpenOption::CREATE_NEW),
						static_cast<$OpenOption*>($StandardOpenOption::WRITE)
					})));
					fileCreated = true;
				} catch ($AccessDeniedException& ade) {
					$init($LinkOption);
					bool var$0 = $Files::isRegularFile(lockFilePath, $$new($LinkOptionArray, {$LinkOption::NOFOLLOW_LINKS}));
					if (var$0 && isParentWritable(lockFilePath)) {
						continue;
					} else {
						$throw(ade);
					}
				} catch ($FileAlreadyExistsException& ix) {
					$init($LinkOption);
					bool var$1 = $Files::isRegularFile(lockFilePath, $$new($LinkOptionArray, {$LinkOption::NOFOLLOW_LINKS}));
					if (var$1 && isParentWritable(lockFilePath)) {
						try {
							$init($StandardOpenOption);
							$assign(channel, $FileChannel::open(lockFilePath, $$new($OpenOptionArray, {
								static_cast<$OpenOption*>($StandardOpenOption::WRITE),
								static_cast<$OpenOption*>($StandardOpenOption::APPEND)
							})));
						} catch ($NoSuchFileException& x) {
							continue;
						} catch ($IOException& x) {
							break;
						}
					} else {
						break;
					}
				}
			}
			if (channel == nullptr) {
				continue;
			}
			$set(this, lockFileChannel, channel);
			bool available = false;
			try {
				available = $nc(this->lockFileChannel)->tryLock() != nullptr;
			} catch ($IOException& ix) {
				available = fileCreated;
			} catch ($OverlappingFileLockException& x) {
				available = false;
			}
			if (available) {
				$nc(FileHandler::locks)->add(this->lockFileName);
				break;
			}
			$nc(this->lockFileChannel)->close();
		}
	}
	$set(this, files, $new($FileArray, this->count));
	for (int32_t i = 0; i < this->count; ++i) {
		$nc(this->files)->set(i, $(generate(this->pattern, i, unique)));
	}
	if (this->append) {
		open($nc(this->files)->get(0), true);
	} else {
		rotate();
	}
	$var($Exception, ex, em->lastException);
	if (ex != nullptr) {
		if ($instanceOf($IOException, ex)) {
			$throw($cast($IOException, ex));
		} else if ($instanceOf($SecurityException, ex)) {
			$throw($cast($SecurityException, ex));
		} else {
			$throwNew($IOException, $$str({"Exception: "_s, ex}));
		}
	}
	setErrorManager($$new($ErrorManager));
}

$File* FileHandler::generate($String* pattern, int32_t generation, int32_t unique) {
	return generate(pattern, this->count, generation, unique);
}

$File* FileHandler::generate($String* pat, int32_t count, int32_t generation, int32_t unique) {
	$init(FileHandler);
	$useLocalCurrentObjectStackCache();
	$var($Path, path, $Paths::get(pat, $$new($StringArray, 0)));
	$var($Path, result, nullptr);
	bool sawg = false;
	bool sawu = false;
	$var($StringBuilder, word, $new($StringBuilder));
	$var($Path, prev, nullptr);
	{
		$var($Iterator, i$, $nc(path)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Path, elem, $cast($Path, i$->next()));
			{
				if (prev != nullptr) {
					$assign(prev, prev->resolveSibling($(word->toString())));
					$assign(result, result == nullptr ? prev : $nc(result)->resolve(prev));
				}
				$var($String, pattern, $nc(elem)->toString());
				int32_t ix = 0;
				word->setLength(0);
				while (ix < $nc(pattern)->length()) {
					char16_t ch = pattern->charAt(ix);
					++ix;
					char16_t ch2 = (char16_t)0;
					if (ix < pattern->length()) {
						ch2 = $Character::toLowerCase(pattern->charAt(ix));
					}
					if (ch == u'%') {
						if (ch2 == u't') {
							$var($String, tmpDir, $System::getProperty("java.io.tmpdir"_s));
							if (tmpDir == nullptr) {
								$assign(tmpDir, $System::getProperty("user.home"_s));
							}
							$assign(result, $Paths::get(tmpDir, $$new($StringArray, 0)));
							++ix;
							word->setLength(0);
							continue;
						} else if (ch2 == u'h') {
							$assign(result, $Paths::get($($System::getProperty("user.home"_s)), $$new($StringArray, 0)));
							if ($VM::isSetUID()) {
								$throwNew($IOException, "can\'t use %h in set UID program"_s);
							}
							++ix;
							word->setLength(0);
							continue;
						} else if (ch2 == u'g') {
							$assign(word, word->append(generation));
							sawg = true;
							++ix;
							continue;
						} else if (ch2 == u'u') {
							$assign(word, word->append(unique));
							sawu = true;
							++ix;
							continue;
						} else if (ch2 == u'%') {
							$assign(word, word->append(u'%'));
							++ix;
							continue;
						}
					}
					$assign(word, word->append(ch));
				}
				$assign(prev, elem);
			}
		}
	}
	if (count > 1 && !sawg) {
		$assign(word, word->append(u'.')->append(generation));
	}
	if (unique > 0 && !sawu) {
		$assign(word, word->append(u'.')->append(unique));
	}
	if (word->length() > 0) {
		$var($String, n, word->toString());
		$var($Path, p, prev == nullptr ? $Paths::get(n, $$new($StringArray, 0)) : $nc(prev)->resolveSibling(n));
		$assign(result, result == nullptr ? p : $nc(result)->resolve(p));
	} else if (result == nullptr) {
		$assign(result, $Paths::get(""_s, $$new($StringArray, 0)));
	}
	if (path->getRoot() == nullptr) {
		return $nc(result)->toFile();
	} else {
		return $nc($($nc($(path->getRoot()))->resolve(result)))->toFile();
	}
}

void FileHandler::rotate() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Level, oldLevel, getLevel());
		$init($Level);
		setLevel($Level::OFF);
		$StreamHandler::close();
		for (int32_t i = this->count - 2; i >= 0; --i) {
			$var($File, f1, $nc(this->files)->get(i));
			$var($File, f2, $nc(this->files)->get(i + 1));
			if ($nc(f1)->exists()) {
				if ($nc(f2)->exists()) {
					f2->delete$();
				}
				f1->renameTo(f2);
			}
		}
		try {
			open($nc(this->files)->get(0), false);
		} catch ($IOException& ix) {
			reportError(nullptr, ix, $ErrorManager::OPEN_FAILURE);
		}
		setLevel(oldLevel);
	}
}

void FileHandler::publish($LogRecord* record) {
	$synchronized(this) {
		$beforeCallerSensitive();
		if (!isLoggable(record)) {
			return;
		}
		$StreamHandler::publish(record);
		flush();
		if (this->limit > 0 && ($nc(this->meter)->written >= this->limit || $nc(this->meter)->written < 0)) {
			$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FileHandler$1, this)));
		}
	}
}

void FileHandler::close() {
	$synchronized(this) {
		$StreamHandler::close();
		if (this->lockFileName == nullptr) {
			return;
		}
		try {
			$nc(this->lockFileChannel)->close();
		} catch ($Exception& ex) {
		}
		$synchronized(FileHandler::locks) {
			$nc(FileHandler::locks)->remove(this->lockFileName);
		}
		$$new($File, this->lockFileName)->delete$();
		$set(this, lockFileName, nullptr);
		$set(this, lockFileChannel, nullptr);
	}
}

void clinit$FileHandler($Class* class$) {
	FileHandler::$assertionsDisabled = !FileHandler::class$->desiredAssertionStatus();
	$assignStatic(FileHandler::locks, $new($HashSet));
}

FileHandler::FileHandler() {
}

$Class* FileHandler::load$($String* name, bool initialize) {
	$loadClass(FileHandler, name, initialize, &_FileHandler_ClassInfo_, clinit$FileHandler, allocate$FileHandler);
	return class$;
}

$Class* FileHandler::class$ = nullptr;

		} // logging
	} // util
} // java